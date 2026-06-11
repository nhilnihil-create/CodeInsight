#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    int n;
    cin >> n;
    vector<int>l(n),r(n);
    for(int i = 0; i < n; i++) cin >> l[i] >> r[i];
    sort(l.begin(),l.end()),sort(r.begin(),r.end());
    int ans = 0;
    if(n % 2 == 1)
    {
        int l1 = l[n/2];
        int r1 = r[n/2];
        ans = r1 - l1 + 1;
    }
    else
    {
        int l2 = l[n/2-1]+l[n/2];
        int r2 = r[n/2-1]+r[n/2];
        ans =  r2 - l2 + 1;
    }
    cout << ans << endl;
}