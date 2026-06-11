#include <bits/stdc++.h>
 
using namespace std;
 
#define int long long
#define M 1000000007
 
signed main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	
	int n;
	cin >> n;
	string s,t;
	cin >> s >> t;
	for(int i=0;i<n;i++){
		cout << s[i] << t[i];
	}
}