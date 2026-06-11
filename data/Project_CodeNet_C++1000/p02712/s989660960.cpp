#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
 
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   
 	ll ans=0,i,l;//,s;
 	
 	cin >> l;
 	
 	for(i=1; i<=l; i++){
 		
 		//s=i;
 		
 		if(i%3==0||i%5==0){
		 ans=ans+0;
		 }else{
		 ans=ans+i;	
		 }
		 
	 }
	 
	 cout << ans << endl;
 	
return 0;   
}
