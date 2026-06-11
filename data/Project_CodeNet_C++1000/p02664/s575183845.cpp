#include <bits/stdc++.h>
#define lsb(x) (x & (-x))
#define ll long long
#define ull unsigned long long
#define Test(tt) cout << "Case #" << tt << ": "

using namespace std;



int main() {
#ifdef HOME
    ifstream cin("A.in");
    ofstream cout("A.out");
#endif
    //int ;
    ios::sync_with_stdio(false);
    cin.tie(0), cout.tie(0);
	
	string str;
	cin >> str;
	for(auto it : str) {
		if(it == '?') {
			cout << 'D';
		}
		else {
			cout << it;
		}
	}

    return 0;
}
