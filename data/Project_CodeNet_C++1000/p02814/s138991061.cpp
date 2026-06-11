#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (ll i = 0; i < (ll)(n); i++)
using ll = long long;
using ld = long double;
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
#define rep3(i, n) for (ll i = 1; i < (ll)(n+1); i++)
#define rep4(i, s, n) for (ll i = (s); i < (ll)(n+1); i++)
#define repr(i,n) for (ll i = (n-1); i>=0;i--)
#define repr3(i,n) for(ll i = (n);i>0;i--)
#define stlen(s) ll s.size()-1
#define all(v) v.begin(), v.end()
#define cout(n) cout<<std::fixed<<std::setprecision(n)
using Graph = vector<vector<int>>;
#define INF1  INT_MAX;
#define INF2  LLONG_MAX;
#define PI  3.14159265358979323846;

ll GCD(ll a,ll b){
  ll r = a % b;
  if(r==0){
    return b;
  }
  else{
    return GCD(b,r);
  }

}



int main() {
    
    int N;
    ll M;
    cin>>N>>M;
    ll A[N];
    rep(i,N){
        cin>>A[i];
        A[i]/=2;
    }
    int ord2=0;
    
    while(true){
        int count=0;
        rep(i,N){
        if(A[i]%2==1){
           count++;
        }
        
        }
        if(count==N){
            break;
        }
        else if(count==0){

        rep(i,N){
            A[i]/=2;
        }
        ord2++;
        
        }
        else{
            cout<<0<<endl;
            return 0;
        }

    }
    ll lcm=1;
    rep(i,N){
        ll gcd =GCD(lcm,A[i]);
        lcm=lcm*A[i]/gcd;
        if(lcm>M){
            cout<<0<<endl;
            return 0;
        }
        
    }
    rep(i,ord2){
        lcm*=2;
    }
    if(lcm>M){
        cout<<0<<endl;
    }
    else{
        cout<<((M/lcm)/2+(M/lcm)%2)<<endl;
    }
   
return 0;
}