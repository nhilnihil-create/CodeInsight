#include <bits/stdc++.h>
#define ll long long
#define rep(i,a,b) for(long long i=a; i<b; i+=1)
#define repr(i,a,b) for(long long i=a; i<=b; i+=1)
#define vec vector<ll>
#define map map<char,int>
#define repa(p,A) for(auto p:A)
#define pb push_back
#define sort(a) sort(a.begin(),a.end())
//#define reverse(a) reverse(a.begin(),a.end())
const double PI=acos(-1);
using namespace std;

int main() {
    ll N;
    cin>>N;
    string S=" ";
    
    while(N) {
        --N;
        S+=char('a'+N%26);
        N/=26;
        }
        reverse(S.begin(), S.end());
        cout<<S<<endl;
}
