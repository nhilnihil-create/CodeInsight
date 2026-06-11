#include<iostream>
#include<math.h>
#include<vector>
#include<array>
#include<algorithm>
#include<numeric>
#include<map>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef vector<ll> vec;
typedef vector<vector<ll>> mat;
ll INF=pow(10,18);

struct LazySegmentTree{
    int n;
    vec node,lazy;
    
    LazySegmentTree(vec v){
        int s=v.size();
        n=1;
        while(n<s)n*=2;
        node.resize(2*n-1);
        lazy.resize(2*n-1,0);

        for(int i=0;i<s;i++)node[i+n-1]=v[i];
        for(int i=n-2;i>=0;i--)node[i]=node[2*i+1]+node[2*i+2];
    }

    //k番目のノードについて遅延評価
    void eval(int k,int l,int r){
        if(lazy[k]!=0){
            node[k]+=lazy[k];

            if(r-l>1){
                lazy[2*k+1]+=lazy[k]/2;
                lazy[2*k+2]+=lazy[k]/2;
            }
            lazy[k]=0;
        }
    }

    //[a,b)にxを加算、kは区間[l,r)の節点
    void add(int a,int b,ll x,int k,int l,int r){
        eval(k,l,r);

        if(b<=l || r<=a)return;

        if(a<=l && r<=b){
            lazy[k]+=x*(ll)(r-l);
            eval(k,l,r);
        }

        else{
            add(a,b,x,2*k+1,l,(l+r)/2);
            add(a,b,x,2*k+2,(l+r)/2,r);
            node[k]=node[2*k+1]+node[2*k+2];
        }
    }

    //[a,b)の区間和を取得
    ll getsum(int a,int b,int k,int l,int r){
        if(b<=l || r<=a) return 0;

        eval(k,l,r);
        if(a<=l && r<=b) return node[k];
        ll vl=getsum(a,b,2*k+1,l,(l+r)/2);
        ll vr=getsum(a,b,2*k+2,(l+r)/2,r);
        return vl+vr;
    }   
};

int main(){
    int N;cin>>N;
    ll M,V,P;cin>>M>>V>>P;
    vec A(N);
    for(int i=0;i<N;i++) cin>>A[i];
    sort(A.begin(),A.end());
    LazySegmentTree LST(A);
    A.push_back(INF);
    int ans=0;
    for(int i=0;i<N;i++){
        auto itr=upper_bound(A.begin(),A.end(),A[i]);
        if(N-distance(A.begin(),itr)<P){
            ans++;
            continue;
        }
        itr=upper_bound(A.begin(),A.end(),A[i]+M);
        if(N-distance(A.begin(),itr)>=P) continue;
        if(P+i>=V){
            ans++;
            continue;
        }
        LST.add(i+1,N-P+1,-A[i]-M,0,0,LST.n);
        if(-LST.getsum(i+1,N-P+1,0,0,LST.n) >= M*(V-P-i)) ans++;
        LST.add(i+1,N-P+1,A[i]+M,0,0,LST.n);
    }
    cout<<ans<<endl;
    return 0;
}