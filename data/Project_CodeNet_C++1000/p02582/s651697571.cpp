#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF 999999999
#define rep(i,n) for(int i=0;i<n;i++)
const ll MOD = 1000000007;
ll cnt =0,ans=0;
const int MAX = 510000;

int main(){
     string s;
     cin >> s;

     if(s == "RRR"){
          cout << 3 << endl;
          return 0;
     }
     if(s == "RRS" || s == "SRR"){
          cout << 2 << endl;
          return 0;
     }
     if(s == "SRS" || s == "SSR" || s == "RSS" || s == "RSR"){
          cout << 1 << endl;
          return 0 ;
     }
      cout << 0 << endl;
}