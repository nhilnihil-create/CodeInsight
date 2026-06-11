#include <bits/stdc++.h>
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<pair<int, int> > a(n);
    for(int i = 0; i < n; i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.begin(), a.end(), greater<pair<int, int> >());
    vector<vector<long long> > dp(n + 1, vector<long long>(n + 1, 0));
    for(int i = 0; i < a.size(); i++){
        int val = a[i].first;
        int pos = a[i].second;
        int numb = i + 1;
        for(int x = 0; x <= numb; x ++){
            if(x >= 1)
                dp[x][numb - x] = max(dp[x-1][numb-x] + 1LL * val * abs(pos - x + 1), dp[x][numb - x]);
            if(numb - x >= 1)
                dp[x][numb - x] = max(dp[x][numb-x-1] + 1LL * val * abs(pos - (n - (numb - x))), dp[x][numb - x]);
        }
    }
    long long _max = 0;
    for(int i = 0; i <= n; i++){
        _max = max(dp[i][n - i], _max);
    }
    cout << _max;
}
