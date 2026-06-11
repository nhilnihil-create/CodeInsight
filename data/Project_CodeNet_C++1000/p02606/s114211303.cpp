#include<bits/stdc++.h>

using namespace std;

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    
    
    int l, r, d;
    cin >> l >> r >> d;
    l = (l - 1) / d;
    r = r / d;

    cout << (r - l);

	return 0;
}