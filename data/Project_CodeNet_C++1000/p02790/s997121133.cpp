#include <bits/stdc++.h>
using namespace std;

#define ALL(v) v.begin(), v.end()
#define V vector
#define P pair
#define ld long double
#define ll long long
#define mod 1000000007
#define IINF INT_MAX
#define INF 1LL << 30


int main() {
    int a, b; cin >> a >> b;
    string as = "";
    for(int i = 0; i < b; i++){
        as += to_string(a);
    }
    string bs = "";
    for(int i = 0; i < a; i++){
        bs += to_string(b);
    }
    if(as < bs) cout << as << endl;
    else cout << bs << endl;

    return 0;
}
