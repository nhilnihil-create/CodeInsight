#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(i = 0;i < n;++i)
#define all(v) v.begin(), v.end()
using ll = long long;

int main()
{
    ll i,j;
    string t;
    cin >> t;
    for(i = 0;i < t.size();++i){
        if(t.at(i) == '?') t.at(i) = 'D';
    }
    cout << t << endl;

    return 0;
}