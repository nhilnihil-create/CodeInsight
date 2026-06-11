#include<bits/stdc++.h>
using namespace std;
#define f(x,y,z) for(int x=y;x<z;++x)
typedef long long ll;
int n, h;
string s;
map<string,bool> m;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);
    cin >> n;
    while(n--) {
        cin >> s;
        if(!m[s]) ++h, m[s] = true;
    }
    cout << h << '\n';
}