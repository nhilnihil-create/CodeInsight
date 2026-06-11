#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define zero_pad(num) setfill('0') << std::right << setw(num)
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;

int main() {
    int n;
    cin >> n;
    string s;
    cin >> s;
    int l = 0;
    int r = n - 1;
    int ans = 0;
    while(l < r){
        while(s[l] == 'R'){
            l++;
            if(l == r)break;
        }
        while(s[r] == 'W'){
            r--;
            if(l == r)break;
        }
        if(s[l] == 'W' && s[r] == 'R'){
            swap(s[l], s[r]);
            l++;
            r--;
            ans++;
        }
    }
    cout << ans << endl;
}