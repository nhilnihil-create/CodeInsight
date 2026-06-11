#include<bits/stdc++.h>
using namespace std;
const int maxn = 320;
int g[maxn][maxn];
bool good[maxn];

pair < long long , long long > solve(long long len, int d){
    if(len == 1) return {0, d};
    auto ans = solve(len >> 1, d);
    ans.first *= 2LL;
    ans.second = ans.second * 10 + ans.second;
    ans.first++;
    ans.second = ans.second / 10 + ans.second % 10;
    if(ans.second >= 10){
        ans.first++;
        ans.second = ans.second / 10 + ans.second % 10;
    }
    if(len & 1){
        ans.second = ans.second * 10 + d;
        ans.first++;
        ans.second = ans.second / 10 + ans.second % 10;   
    }
    if(ans.second >= 10){
        ans.first++;
        ans.second = ans.second / 10 + ans.second % 10;
    }
    return ans;
}

int main(){
	ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int n;
    long long ans = 0;
    cin >> n;
    vector < int > v;
    for(int i = 0 ; i < n ; ++i){
        long long d, c;
        cin >> d >> c;
        auto u = solve(c, d);
        ans += u.first;
        //cout << u.first << ' ' << u.second << '\n';
        v.push_back(u.second);
    }
    int sum = v[0];
    for(int i = 1 ; i < n ; ++i){
        sum = sum * 10 + v[i];
        ans++;
        sum = sum / 10 + sum % 10;
        if(sum >= 10){
            ans ++;
            sum = sum / 10 + sum % 10;
        }
    }
    cout << ans << '\n';
    return 0;
}
