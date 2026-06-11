#include <bits/stdc++.h>
#define rep(i,k,n) for(int i=k;i<n;++i)
#define repe(i,k,n) for(int i=k;i<=n;++i)

using namespace std;

int main()
{
    cin.tie(0);cout.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i,0,n)
    {
        cin >> a[i];
    }

    int res = 1e9;
    repe(i,1,100)
    {
        int temp=0;
        for (auto c:a){
            temp += (c-i)*(c-i);
        }
        res = min(temp,res);
    }
    cout << res;
    return 0;
}
