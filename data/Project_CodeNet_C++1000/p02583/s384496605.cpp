#include<bits/stdc++.h>
using namespace std;
#define ll long long 
#define INF 999999999
#define rep(i,n) for(int i=0;i<n;i++)
const ll MOD = 1000000007;
ll cnt =0,ans=0;
const int MAX = 510000;

int main(){
    int n;     cin >> n;
    ll l[n];
    for(int i=0;i<n;i++){
         cin >> l[i];
    }

    for(int i=0;i<n;i++){
         for(int j=i;j<n;j++){
              for(int k=j;k<n;k++){
                  if(l[i] == l[j] || l[i] == l[k] || l[j] == l[k])continue; 
                  ll maxl,midl,minl;
                  ll all = l[i] + l[j] + l[k];
                  maxl = max(l[i],max(l[j],l[k]));
                  minl = min(l[i],min(l[j],l[k]));
                  midl = all - maxl - minl;
                  if( maxl < minl+midl ){
                       ans++;
                      // cout << i+1 <<" "<< j+1 <<" "<< k+1 << endl;
                  }

              }
         }
    }
    cout << ans << endl;
}