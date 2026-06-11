#include <bits/stdc++.h>
using namespace std;
#define Hello ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define ll long long
int n, m, x;
int c[20];
vector<vector<int>> v, ans;
vector<int> temp;
void rec(int idx){
    if(idx >= n){
        ans.push_back(temp);
        return;
    }
    temp.push_back(idx);
    rec(idx + 1);
    temp.pop_back();
    rec(idx + 1);
}
int main()
{
    Hello
    v.resize(20);
    cin >> n >> m >> x;
    for(int i = 0; i < n; i++){
        cin >> c[i];
        for(int j = 0, a; j < m; j++){
            cin >> a;
            v[i].push_back(a);
        }
    }
    rec(0);
    int mn = 2e9;
    for(int i = 0; i < ans.size(); i++){
        int arr[m + 5] = {}, amount = 0;
        for(int j = 0; j < ans[i].size(); j++){
            amount += c[ans[i][j]];
            for(int k = 0; k < m; k++){
                arr[k] += v[ans[i][j]][k];
            }
        }
        bool ok = true;
        for(int j = 0; j < m; j++)
            if(arr[j] < x)
                ok = false;
        if(ok)
            mn = min(mn, amount);
    }
    if(mn == 2e9)
        cout << -1;
    else
        cout << mn;
    return 0;
}