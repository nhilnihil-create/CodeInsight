#include<bits/stdc++.h>
 
using namespace std;
 
#define D(x) cout << (#x) << " is " << x << endl;
#define Q int t; scanf("%d", &t); for(int q=1; q<=t; q++)
typedef long long int lli;
typedef pair<int, int> pi;
typedef pair<lli, lli> pii;


int main()
{
    int n;
    cin >> n;
    lli a, b;
    lli mx1=-1e10, mx2=-1e10, mn1=1e10, mn2=1e10;
	for(int i=0; i<n; i++){
		cin >> a >> b;
		mx1 = max(mx1, a+b);
		mx2 = max(mx2, a-b);
		mn2 = min(mn2, a-b);
		mn1 = min(mn1, a+b);
	}
	cout << max(mx1-mn1, mx2-mn2) << endl;
	
 
    return 0;
}
