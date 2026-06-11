#include<bits/stdc++.h>
using namespace std;

#define int long long

typedef pair<int,int>pint;
typedef vector<int>vint;
typedef vector<pint>vpint;
#define pb push_back
#define mp make_pair
#define fi first
#define se second
#define all(v) (v).begin(),(v).end()
#define rep(i,n) for(int i=0;i<(n);i++)
#define reps(i,f,n) for(int i=(f);i<(n);i++)
#define each(it,v) for(__typeof((v).begin()) it=(v).begin();it!=(v).end();it++)
template<class T,class U>void chmin(T &t,U f){if(t>f)t=f;}
template<class T,class U>void chmax(T &t,U f){if(t<f)t=f;}

int cnt;

void insertionSort(vint &A,int g){
    rep(i,A.size()){
        int cur=i;
        while(cur-g>=0&&A[cur-g]>A[cur]){
            swap(A[cur-g],A[cur]);
            cnt++;
            cur-=g;
        }
    }
}

void shellSort(vint &A){
    vint G;
    int h=1;
    while(h<=A.size()){
        G.pb(h);
        h=3*h+1;
    }
    reverse(all(G));
    rep(i,G.size())insertionSort(A,G[i]);

    cout<<G.size()<<endl;
    rep(i,G.size()){
        if(i)cout<<" ";
        cout<<G[i];
    }cout<<endl;
    cout<<cnt<<endl;

    rep(i,A.size())cout<<A[i]<<endl;
}

signed main(){
    int N;cin>>N;
    vint A(N);rep(i,N)cin>>A[i];

    shellSort(A);
    return 0;
}