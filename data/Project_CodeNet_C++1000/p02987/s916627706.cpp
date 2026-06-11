#include <bits/stdc++.h>
#define fast_io ios :: sync_with_stdio(false);
using namespace std;

int main() {
	cout << fixed << setprecision(3);
	fast_io;
	string s; cin >> s;
	int n = 0;
	for (int i = 0 ; i<4 ; i++){
		for (int j = 0 ; j<4 ; j++){
			if (s[i] == s[j])
				n++;
    	}
  	}
  
  	if (n == 8)
    	cout << "Yes\n";
  	else
    	cout << "No\n";
	return 0;	
}