#include <bits/stdc++.h>

using namespace std;


int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long  n;

    cin >> n;
    vector<long long > a(n);

    for(long long  i=0;i<n;++i) {
        cin >> a[i];
    }

    sort(a.begin(),a.end());
    if (a[0] == 0){
        cout << 0;
        return 0;

    }


    long long  res = 1;
    for(long long  i = 0; i < n; i++){
    if (res > (long long)1e18 / a[i]){
        cout << -1;
        return 0;
    }else {
        res *=a[i];
    }
    }
        cout << res;


}
