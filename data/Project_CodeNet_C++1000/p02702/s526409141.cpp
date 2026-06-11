#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

const long MOD = 1000000007;
typedef pair<int, int> P;
typedef long long ll;

int main(){
    string s;
    cin >> s;
    
    const int NUM = 2019;
    
    reverse(s.begin(), s.end());

    ll t = 0;
    ll d = 1;
    ll l[NUM];
    fill(l, l+NUM, 0);
    for(int i=0; i<s.length(); i++){
        t = t + d*(s[i]-'0');
        t = t % NUM;
        // cout << t << endl;
        l[t]++;

        d = d * 10;
        d = d % NUM;
    }

    ll ans = 0;
    for(int i=0; i<NUM; i++){
        if(i == 0) ans = ans + l[i];
        ans = ans + l[i]*(l[i]-1)/2;
    }

    cout << ans << endl;

    return 0;
}
