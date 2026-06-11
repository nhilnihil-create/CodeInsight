#include <bits/stdc++.h>

#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
using namespace std;


int main()
{

    ll n, m ;
    cin >> n >> m;
    vector<int> v(n+1, 0);

    rep(i, m) {
        int tmp;
        cin >> tmp;
        v[tmp] = 1;
    }

    vector<unsigned long long> ress(n+1);
    ress[0] = 1;
    if (v[1] == 1) {
        ress[1] = 0;
    }
    else {
        ress[1] = 1;
    }

    for (unsigned long long i = 2; i <= n; ++i) {
        if(v[i] == 1) {
            ress[i] = 0;
        }
        else {
            ress[i] = (ress[i-1] + ress[i-2])  % 1000000007 ;
        }
    }
    cout << ress[n]<< endl;


    return 0;
}
