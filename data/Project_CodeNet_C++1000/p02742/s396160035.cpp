#include <bits/stdc++.h>

using namespace std;

typedef long long int ll;

int main(){
	ll h,w;
	cin >> h >> w;
	if(w==1 || h==1){
		cout << 1 << "\n";
		return 0;
	}
	ll hlf = (h + 1) / 2;
	ll rem = h - hlf;
	cout << hlf * ((w + 1) / 2) + rem * (w / 2);	
	return 0;
}
