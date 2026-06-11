#include <bits/stdc++.h>

using namespace std;
int main()
{
    long long  n;
    cin.tie(0);
    ios::sync_with_stdio(false);
    cin >> n;
    vector<pair<long long ,int>> v;
    for (long long  i=2;i*i<=n;++i){
        int cnt=0;
        while (n % i == 0){
            n /= i;
            cnt ++;
        }
        if (cnt != 0) v.emplace_back(i,cnt);
    }
    if (n!=1) v.emplace_back(n,1);

    int res=0;
    for (auto c:v){
        int x= c.second;
        int a=1;
        while(x >= a){
            res++;

            x -=a;
            a++;
        }
    }
    cout << res;
    return 0;
}
