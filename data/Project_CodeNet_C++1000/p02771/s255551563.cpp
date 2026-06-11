#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
 
int main() {
 
   ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
   
 	  ll a,b,c;
 	  
 	  cin >> a >> b >> c;
 	  
 	  if(a!=b&&b==c){
 	  	cout << "Yes" << endl;
	   }else if(c!=a&&b==a){
	   	cout << "Yes" << endl;
	   }else if(b!=a&&a==c){
	   	cout << "Yes" << endl;
	   }else{
	   	cout << "No" << endl;
	   }
   
return 0;   
}
