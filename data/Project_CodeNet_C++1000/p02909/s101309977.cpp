#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
const int INF = 1<<30;
const long long LINF = 1LL<<60;
const long long MOD = (long long)1e9 + 7;

int main(){
    string s;
    cin >> s;
    vector<string> ans = {"Sunny", "Cloudy", "Rainy"};
    cout << ans[(find(begin(ans), end(ans), s) - begin(ans) + 1) % 3] << endl;
    return 0;
}
