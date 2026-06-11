#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    string S;

    cin >> S;

    if(S=="SAT") {
        cout << 1 << endl;
    } else if(S=="FRI") {
        cout << 2 << endl;
    } else if(S=="THU") {
        cout << 3 << endl;
    } else if(S=="WED") {
        cout << 4 << endl;
    } else if(S=="TUE") {
        cout << 5 << endl;
    } else if(S=="MON") {
        cout << 6 << endl;
    } else if(S=="SUN") {
        cout << 7 << endl;
    }

    return 0;
    
}