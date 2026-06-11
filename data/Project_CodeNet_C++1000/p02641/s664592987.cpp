#include <bits/stdc++.h>
using namespace std;

long long n, x, h, l, r, ans;
map <long long, bool> ada;

int main() {
	cin >> x >> n;
	for(int i = 0; i < n; i++){
		cin >> h;
		ada[h] = 1;
	}
	l = r = x;
	while(1){
		if(ada[l])l--;
		else{ans = l; break;}
		if(ada[r])r++;
		else{ans = r; break;}
	}
	cout << ans << '\n';
}
//asldkfjlas