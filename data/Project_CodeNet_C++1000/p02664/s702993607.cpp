#include <bits/stdc++.h>
using namespace std;

#define watch(x) cerr << (#x) << ": " << (x) << endl

typedef long long LL;

int n;
string t;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> t;
    n = t.length();

    for(char& c : t) {
        if(c == '?') {
            c = 'D';
        }
    }

    cout << t << endl;
    
    return 0;
}
