#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);	
    
    string s;
    int n=0, max=0;
    cin >> s;
    for(int i=0; i<3; ++i)
		if(s[i] == 'R') {
			n++;
			max = n;
		} else {	
			n = 0;
		}
	if(n>max)
		cout << n;
	else 
		cout << max;
    return 0;
} 
 
