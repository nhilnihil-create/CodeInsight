#include <bits/stdc++.h>

using namespace std; 
 
#define int long long
#define M 1000000007
 
signed main(){
	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	
	int a,b,c,d;
	cin >> a >> b >> c >> d;
	cout << max(b*d,max(b*c,max(a*c,a*d))) << endl;
}
