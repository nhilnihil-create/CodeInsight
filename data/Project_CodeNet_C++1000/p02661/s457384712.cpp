#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define endl "\n"

int main ()
{
	
	ios_base::sync_with_stdio(false);
 	cin.tie(NULL);
 	#define int ll
 	   
	int n;
	cin >> n;
	
	vector <int> a(n), b(n);
	for (int i=0; i<n; i++){
	    cin >> a[i] >> b[i];
	}
	
	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	
	if (n&1) cout << b[n/2] - a[n/2] + 1<< endl;
	else{
	    int median1 = (a[n/2-1] + a[n/2]);
	    int median2 = (b[n/2-1] + b[n/2]);
	    cout << (median2 - median1) + 1 << endl;
	}
     
     
	return 0;
	
}
