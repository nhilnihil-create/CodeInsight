#include <bits/stdc++.h>
 #define rep(i,n) for(int i=1;i<=n;i++)
 using namespace std;

  int gcd(int a,int b){
      if(a%b==0)return b;
    return gcd(b,a%b);
  }

  int main(){
       int k;
        cin >> k;
        int ans=0;
        rep(i,k)rep(j,k)rep(l,k){
            ans+=gcd(gcd(i,j),l);
        }
        cout << ans << endl;
        return 0;
    
  }