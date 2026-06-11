#include <bits/stdc++.h>
using namespace std;
const int N = 2e5 + 5;

int n, a, b, c, d;
int x[N];
bool valid;
string s;

int main() {

    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> a >> b >> c >> d;
    cin >> s;
    for(int i = 0; i < s.size(); i++) {
        if(s[i] == '#') x[i + 1] = 2;
        else x[i + 1] = 1;
    }
    valid = true;
    for(int i = a; i < c; i++) {
        if(x[i] == 2 && x[i + 1] == 2) valid = false;
    }
    for(int i = b; i < d; i++) {
        if(x[i] == 2 && x[i + 1] == 2) valid = false;
    }
    if(!valid) cout << "No\n";
    else if(c < d) cout << "Yes\n";
    else {
        valid = false;
        for(int i = b - 1; i < d; i++) {
            if(x[i] == 1 && x[i + 1] == 1 && x[i + 2] == 1) valid = true;
        }
        if(valid) cout << "Yes\n";
        else cout << "No\n";
    }
}