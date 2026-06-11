#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;cin >> n >> m;
    if(n == 1 && m == 0){
        cout << 0 << endl;
        return 0;
    }
    vector<int> num(n, -1);
    bool exist = true;
    for (int i = 0; i < m; i++)
    {
        int s, c;cin >> s >> c;
        if(num.at(n-s) == -1)num.at(n-s) = c;
        else if(num.at(n-s) != c)exist = false;
    }
    if(num.at(n-1) == 0 && num.size() > 1)exist = false;
    if(num.at(n-1) == 0 && num.size() == 1){
        cout << 0 << endl;
        return 0;
    }
    int ans;
    if(exist){
        ans = max(1, num.at(n-1))*pow(10, n-1);
        for (int i = 1; i < n; i++)
        {
            ans += max(0, num.at(n-1-i))*pow(10, n-i-1);
        }        
    }
    else ans = -1;
    cout << ans << endl;
    return 0;
}