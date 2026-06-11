// dfs
#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
#include <string>
#include <cstdio>

using namespace std;

int ans, n, s;

void dfs(int pos, int t, int sum)
{
    if(t == n) {
        if(sum == s)
            ans++;
        return;
    }
    if(pos > 9)
        return;

    dfs(pos+1, t, sum);
    dfs(pos+1, t+1, sum + pos);
}

int main(void)
{
    while(cin >> n >> s) {
        if(n==0 && s==0) break;
        ans = 0;
        dfs(0, 0, 0);
        cout << ans << endl;
    }

    return 0;
}