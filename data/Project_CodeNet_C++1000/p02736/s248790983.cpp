#include <bits/stdc++.h>
using namespace std;
#define finish(x) return cout << x << endl, 0
#define ll long long

int n;
vector <int> a;
int g;

int calc(int x){
    int ret = 0;
    while(x){
        x /= 2;
        ret += x;
    }
    return ret;
}
int solve(){
    int ret = 0;
    for(int i = 0 ; i < n ; i++){
        if(calc(n - 1) != calc(i) + calc(n - i - 1)) continue;
        ret = (ret + a[i]) % 2;
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for(int i = 0 ; i < n ; i++){
        char c;
        cin >> c;
        a.push_back(c - '0' - 1);
    }
    int ans = solve();
    if(ans == 1) finish(1);
    for(auto &i : a) if(i == 1) finish(0);
    for(auto &i : a) i /= 2;
    cout << solve() * 2 << endl;
}
