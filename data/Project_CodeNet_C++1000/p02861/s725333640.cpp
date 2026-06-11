#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
    int n;
    cin >> n;
    vector<pair<int,int>>v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i].first >> v[i].second;
    }
    sort(v.begin(),v.end());
    double len = 0;
    do{
        for(int i = 1; i < n; i++)
        {
            len += sqrt((v[i].first - v[i-1].first)*(v[i].first - v[i-1].first) + (v[i].second - v[i-1].second)*(v[i].second - v[i-1].second));
        }
    }while(next_permutation(v.begin(),v.end()));
    double ans = len;
    for(int i = 1; i <= n; i++)
    {
        ans = ans / i;
    }
    cout << fixed << setprecision(10) << ans << endl;
}
