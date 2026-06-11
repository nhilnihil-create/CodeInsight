#include <bits/stdc++.h>


using namespace std;

#define ll long long

int main(){
   ios::sync_with_stdio(false);
   cin.tie(0);
   int k;
   cin >> k;
   ll ans=0;
   for(int i=1;i<=k;i++) {
	   for(int j=1;j<=k;j++) {
		   for(int ij=1;ij<=k;ij++) {
			   ans+=__gcd(__gcd(i,j),ij);
		   }
	   }
   }
   cout << ans;
   return 0;
}


