#include <bits/stdc++.h>
using namespace std;

#define     F       first
#define     S       second
typedef pair<int, int>  pi;
typedef long long       ll;



int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s, t;
    cin >> s >> t;
    
    int ans=0;
    for (int i=0; i <s.size(); ++i) {
        if (s[i]!=t[i]) {
            ++ans;
        }
    }
    
    cout << ans;


    return 0;
}
