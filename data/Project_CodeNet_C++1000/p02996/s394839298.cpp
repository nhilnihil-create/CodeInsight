#include "bits/stdc++.h"
#define ALL(x) x.begin(),x.end()
#define rep(i,n) for(ll i=0;i<n;++i)
#define END(x) (*(x.end()-1))
#define INF (INT_MAX / 2)
#define VEC2(type,name,w,h) vector<vector<type>>name(h,vector<type>(w))

using namespace std;
typedef long long ll;


template<typename T>
T gcd(T a, T b){
   if (a%b == 0){
       return(b);
   }
   else{
       return(gcd(b, a%b));
   }
}

template<typename T>
T lcm(T a,T b){
    return a/gcd(a,b)*b;
}

int main(void){
    vector<tuple<ll,ll>> t;
    ll a,n,b;
    cin>>n;
    rep(i,n){
        cin>>a>>b;
        t.push_back(make_tuple(b,a));
    }
    ll time=0;
    sort(ALL(t));
    for(auto i : t){
        time+=get<1>(i);
        // cout<<"now-time:"<<time<<"  limit:"<<b<<"  a:"<<a<<endl;
        if(get<0>(i)<time){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
}
/*
*/