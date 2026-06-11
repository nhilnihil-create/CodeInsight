#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, d, ans = 0;
int arr[15][15];
bool solve(int i, int j){
    double ans = 0;
    for(int idx = 0; idx < d; idx++){
        ans += ((arr[i][idx] - arr[j][idx]) * (arr[i][idx] - arr[j][idx]));
    }
    ans = sqrt(ans);
    int ans2 = ans;
    return ans2 == ans;
}
int main()
{
    Hello
    cin >> n >> d;
    for(int i = 0; i < n; i++)
        for(int j = 0; j < d; j++)
            cin >> arr[i][j];
    for(int i = 0; i < n; i++)
        for(int j = i + 1; j < n; j++)
            if(solve(i, j))
                ans++;
    cout << ans;
    return 0;
}
