#include <bits/stdc++.h>
using namespace std;

int main()
{
	int A,B,V,W,T;
	cin >> A >> V;
	cin >> B >> W;
	cin >> T;
	
	string out = "NO";
	if( V > W ) {
		if( abs(A-B) / (double)(V-W) <= T ) {
			out = "YES";
		}
	}
	cout << out;
	
	return 0;
}
