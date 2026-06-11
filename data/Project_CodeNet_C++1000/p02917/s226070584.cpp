#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define ll long long
#define REP(i,n,m) for(int i=(m);i<(n);i++)
using namespace std;
 
  int main(){
      int ans=0;
      int n;
      cin >> n;
    vector<int> a(n),b(n);
    rep(i,n-1){
        cin >> b[i];
    }
    
    for(int i=0;i<n;i++){
        ans+=b[i];
        
        if(b[i-1]<b[i] && i!=0){
        ans=ans-b[i]+b[i-1];
        }
        if(i+2==n){
            ans+=b[i];
        }
    }
      cout << ans << endl;
  }