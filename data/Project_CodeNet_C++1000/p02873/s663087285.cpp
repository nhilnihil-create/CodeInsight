#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>
#include <tuple>
#include <cstdint>
#include <cstdio>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <deque>
#include <unordered_map>
#include <unordered_set>
#include <bitset>
#include <cctype>
#define ll long long int
#define pb push_back
#define rep(i,n) for(int i=0;i<(n);i++)
using namespace std;

int main() {
    string s; cin >> s;
    int n = s.length();
    vector<ll> a;
//cout << n << endl;
    int i = 0, cnt = 1;
    while(i < n - 1){
        if(s[i] == s[i+1]){
            cnt++;
        }else{
            a.pb(cnt);
            cnt = 1;
        }
        i++;
    }
    if(cnt != 1) a.pb(cnt);
    if(s[n-1] != s[n-2]) a.pb(1);

    ll ans = 0;
    int N = a.size();
    if(s[0] == '<'){
        for(int i = 0; i < N-1; i+=2){
            ll MA = max(a[i],a[i+1]);
            ll MI = min(a[i],a[i+1]);
            ans += (1+MA) * MA / 2;
            ans += MI * (MI-1) / 2;
        }
        if(N%2==1) ans += (a[N-1]+1) * a[N-1] / 2;
    }else{
        ans += a[0] * (a[0] + 1) / 2;
        for(int i = 1; i < N -1; i+=2){
            ll MA = max(a[i],a[i+1]);
            ll MI = min(a[i],a[i+1]);
            ans += (1+MA) * MA / 2;
            ans += MI * (MI-1) / 2;
        }
        if(N%2==0) ans += (a[N-1]+1) * a[N-1] / 2;
    }
    cout << ans << endl;
}
