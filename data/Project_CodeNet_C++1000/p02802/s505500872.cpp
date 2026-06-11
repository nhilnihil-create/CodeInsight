#include <bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 2e5 + 5, mod = 1e9 + 7;


int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    map<int, int> mp;
    int n, m;
    cin >> n >> m;
    int c1 = 0, c2 = 0;
    while(m--){
        int x;
        string s;
        cin >> x >> s;
        if(mp[x] == -1) continue;
        if(s[0] == 'A'){
            c1++;
            c2 += mp[x];
            mp[x] = -1;
        }
        else{
            mp[x]++;
        }
    }
    cout << c1 << ' ' << c2;

    return 0;
}
