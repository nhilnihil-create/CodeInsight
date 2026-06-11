#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
int INF = 1000000009;
int dp[100005];
int main()
{
    int n,m;
    cin >> n >> m;
    string s;
    cin >> s;
    int cnt = 0;
    rep(i, s.size())
    {
        if(s[i]=='1'){
            cnt++;
        }else{
            if(cnt>=m){
                cout << -1 << endl;
                return 0;
            }
            cnt = 0;
        }
    }
    reverse(s.begin(), s.end());
    vector<int> v;
    int left = 0;
    int right = 0;
    while(left < n){
        for (int i = m; i > 0;i--){
            right = left + i;
            if(s[right] == '1')continue;
            if(right > n)continue;
            v.push_back(i);
            left = right;
            break;
        }
    }
    reverse(v.begin(), v.end());
    for(auto e:v){
        cout << e << " ";
    }
    cout << endl;
}