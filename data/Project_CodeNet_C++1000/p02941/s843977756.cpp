#include<bits/stdc++.h>
using namespace std;

#define int long long

#define rep(i,n) for(int i=0;i<(n);i++)
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(),(v).end()
#define fi first
#define se second

using vint=vector<int>;
using pint=pair<int,int>;
using vpint=vector<pint>;

template<typename A,typename B>inline void chmin(A &a,B b){if(a>b)a=b;}
template<typename A,typename B>inline void chmax(A &a,B b){if(a<b)a=b;}

template<class A,class B>
ostream& operator<<(ostream& ost,const pair<A,B>&p){
    ost<<"{"<<p.first<<","<<p.second<<"}";
    return ost;
}

template<class T>
ostream& operator<<(ostream& ost,const vector<T>&v){
    ost<<"{";
    for(int i=0;i<v.size();i++){
        if(i)ost<<",";
        ost<<v[i];
    }
    ost<<"}";
    return ost;
}

inline int topbit(unsigned long long x){
    return x?63-__builtin_clzll(x):-1;
}

inline int popcount(unsigned long long x){
    return __builtin_popcountll(x);
}

inline int parity(unsigned long long x){
    return __builtin_parity(x);
}

signed main(){
    int N;cin>>N;
    vint A(N);rep(i,N)cin>>A[i];
    vint B(N);rep(i,N)cin>>B[i];

    priority_queue<pint>que;
    rep(i,N){
        if(A[i]!=B[i])que.emplace(B[i],i);
    }

    int ans=0;
    while(que.size()){
        int val;
        int i;
        tie(val,i)=que.top();
        que.pop();
        int d=B[(i+1)%N]+B[(i+N-1)%N];
        if(B[i]<=d){
            cout<<-1<<endl;
            return 0;
        }

        int r=B[i]%d;
        if(r>A[i]){
            ans+=B[i]/d;
            B[i]=r;
            que.emplace(B[i],i);
            continue;
        }
        if(B[i]>=A[i]&&(B[i]-A[i])%d==0){
            ans+=(B[i]-A[i])/d;
            B[i]=A[i];
            continue;
        }
        cout<<-1<<endl;
        return 0;
    }
    cout<<ans<<endl;
    return 0;
}