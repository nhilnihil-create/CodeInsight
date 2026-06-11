#include<bits/stdc++.h>
#define ll long long
#define fastio  ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MOD=1000000007;
#define PI acos(-1)
using namespace std;
int main(){
      int n; cin >> n ;
      if(n<=81){
      	bool ans = false ;
      	for(int i=1 ; i*i <= n ; i++){
      		  if(n%i==0 && i<=9 && (n/i)<=9)
      		    { 
                    cout << "Yes";
      		  	    ans = true ;
      		  	    break;
				} 
		  }
		  if(!ans) cout << "No" << endl;
	  }
	  else cout << "No" << endl;
}