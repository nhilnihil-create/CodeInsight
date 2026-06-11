#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF 999999999
#define rep(i,n) for(int i=0;i<n;i++)
const ll MOD = 1000000007;
ll cnt =0,ans=0;
const int MAX = 510000;

int main (){
     string s;
     cin >> s ;
     ll n = s.size();
     for(int i=0;i<n;i++){
          ll a = s.at(i)-48;
          ans += a ;
          ans %= 9;
     }
     if(ans == 0) cout << "Yes"  << endl;
     else cout << "No" << endl;
}