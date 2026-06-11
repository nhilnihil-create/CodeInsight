#include <bits/stdc++.h>

using namespace std; 
 
#define int long long
#define M 1000000007
 
signed main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	
	int k;
	cin >> k;
	int a,b;
	cin >> a >> b;
	if(a%k==0||b%k==0){
		cout << "OK" << endl;
		
	}
	else if(a/k<b/k){
		cout << "OK" << endl;
	}
	else{
		cout << "NG" << endl;
	}
}
