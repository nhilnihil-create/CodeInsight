#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
using ll = long long int;
using P = pair<int, int>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
ll mod = 1000000007;

int main() {
    string s,t;
    cin >> s >> t;
    int ans = 0,len = s.size();
    for(int i = 0;i < len;i++) {
        if(s.at(i) != t.at(i)) ans++;
    }
    cout << ans << endl;
}
