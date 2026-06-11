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

    if((1<<topbit(N))==N){
        cout<<"No"<<endl;
        return 0;
    }

    if(N==3){
        cout<<"Yes"<<endl;
        rep(i,5){
            cout<<i+1<<" "<<i+2<<endl;
        }
        return 0;
    }

    cout<<"Yes"<<endl;
    int l=topbit(N);

    int p=1<<l;
    for(int i=1;i+1<p;i++){
        cout<<i<<" "<<i+1<<endl;
        cout<<i+N<<" "<<i+1+N<<endl;
    }
    cout<<p-1<<" "<<N+1<<endl;

    cout<<1<<" "<<p<<endl;
    cout<<p<<" "<<p+1+N<<endl;
    cout<<1<<" "<<p+1<<endl;
    cout<<p+1<<" "<<p+N<<endl;
    for(int i=p+2;i<=N;i++){
        cout<<i-1<<" "<<i+N<<endl;
        cout<<i-p<<" "<<i<<endl;
    }
    return 0;
}