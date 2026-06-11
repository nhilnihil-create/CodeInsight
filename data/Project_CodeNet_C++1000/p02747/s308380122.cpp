#include <bits/stdc++.h>
using namespace std;
struct Fast { Fast() { cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(20);} } fast;


int main() {
	long a, b, c, d;
    string s;
 	cin >> s;
    for (int i = 0; i < s.size(); i += 2){
        if (s[i] == 'h' && s[i + 1] == 'i'){
            continue;
        }else{
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
} 