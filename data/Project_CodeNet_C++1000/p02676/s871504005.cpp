#include<bits/stdc++.h>
#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

int k;
string s;
int main() {
    IOS; cin >> k >> s;
    if((int)s.length()<=k) cout << s;
    else cout << s.substr(0, k) << "...";
    return 0;
}
