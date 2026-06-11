#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
typedef long long ll;
const int INF = 1001001001;

int main() {
    string S;

    cin >> S;

    if(S=="Sunny") {
        cout << "Cloudy" << endl;
    } else if(S=="Cloudy") {
        cout << "Rainy" << endl;
    } else if(S=="Rainy") {
        cout << "Sunny" << endl;
    }

    return 0;
    
}