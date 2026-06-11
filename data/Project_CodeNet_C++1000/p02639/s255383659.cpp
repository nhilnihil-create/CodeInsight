#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;
#define mp make_pair
// GCD inbuilt func: __gcd(a,b)
// LCM formula: (a*b)/__gcd(a,b)

int main(){
	ios::sync_with_stdio(false);
    cin.tie(NULL);
	// CODE goes here
    int a[5];
    int ans;
    for(int i=0;i<5;i++){
    	cin >> a[i];
    	if(a[i]==0) ans=i+1;
    }
    cout << ans << "\n";
	return 0;
}
