#include <bits/stdc++.h>
#pragma GCC optimize ("Ofast")
using namespace std;
vector <int> ans;
int n,x,y;
int main()
{
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(false);
    cin >> n >> x >> y;
    x--;y--;
    ans.resize(n);
    for(int i = 0; i < n-1; i++)
    {
        for(int g = i+1; g < n; g++)
            ans[min(abs(max(x,y)-g)+abs(min(x,y)-i),g-i-1)]++;
    }
    for(int i = 0; i < n-1; i++)
        cout << ans[i] << endl;
}
