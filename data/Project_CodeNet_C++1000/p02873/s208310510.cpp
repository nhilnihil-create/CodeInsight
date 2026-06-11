#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

typedef long long ll;
using namespace std;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    // Create a vector of size n+1 (for extra space) with all values as 0
    vector<int> v(n+1, 0);

    for(int i=0; i<n; i++) {
        // next element is greater, so add 1 to it
        if(s[i] == '<') v[i+1] = v[i]+1;
    }
    for(int i=n-1; i>=0; i--) {
        if(s[i] == '>') v[i] = max(v[i], v[i+1]+1);
    }
    ll ans = 0;
    for(int i=0; i<v.size(); i++) {
        ans += v[i];
    }
    cout << ans << endl;
}