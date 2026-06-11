#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <queue>
#include <utility>
#include <map>
#include <bitset>
#include <numeric>
#define ll long long
using namespace std;
using p = pair<ll, ll>;
ll dx[8]={ 0, 1, 0,-1, 1, 1,-1,-1}; // x軸方向への変位
ll dy[8]={ 1, 0,-1, 0, 1,-1, 1,-1}; // y軸方向への変位

ll n;
string a;
vector<string> ans;
string c = "abcdefghijklm";
void func(ll cnt, string s){
    if(cnt<n){
        ll MAX = 0;
        for(ll i = 0; i < s.length(); i++){
            char b = s[i];
            ll d = b-97;
            MAX = max(MAX, d);
        }
        for(ll i = 0; i <= MAX+1; i++){
            string t = s + c[i];
            func(cnt+1, t);
        }
    }
    else if(cnt==n)
        ans.push_back(s);
}

int main(void) {
    cin >> n;
    a = 'a';
    func(1, a);
    sort(ans.begin(), ans.end());
    for(ll i = 0; i < ans.size(); i++)
        cout << ans[i] << endl;
    return 0;
}
