#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
typedef long long ll;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;

using namespace std;

int main(){
    string s;   cin >> s;
    int l = s.length();
    int cnt = 0;
    for(int i=0; i<l; i++) if(s[i] != s[l-i-1]) cnt++;
    print(cnt/2);
}