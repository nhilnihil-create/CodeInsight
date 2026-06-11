#include <bits/stdc++.h>
#define ll long long int
#define rep(i,a,b) for(long long i=a; i<b; i+=1)
#define repr(i,a,b) for(long long i=a; i<=b; i+=1)
#define vec vector<ll>
#define map map<char,int>
#define repa(p,A) for(auto p:A)
#define pb push_back
#define sort(a) sort(a.begin(),a.end())
#define reverse(a) reverse(a.begin(),a.end())
const double PI=acos(-1);
using namespace std;

int main( ) {
    ll N;
    cin>>N;
    ll count=1;
    vec A(N);
    rep(i,0,N) {
        cin>>A[i];
        if(A[i]==0) {
            cout<<"0"<<endl;
            return 0;
            }
        }
    sort(A);
    rep(i,0,N) {
        if(A[i]<=1000000000000000000/count) {
          count*=A[i];
        }
        else {
            cout<<"-1"<<endl;
            return 0;
        }
          
       
        }
        cout<<count<<endl;

    }