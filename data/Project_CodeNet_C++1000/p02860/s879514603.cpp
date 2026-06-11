#include<bits/stdc++.h>
using namespace std;
using ll = long long;
const ll MOD = 1e9 + 7;
ll fac(ll n){if(n<=1)return 1; else return n*fac(n-1);}
int main()
{
    ll n;
    cin >> n;
    string s;
    cin >> s;
    if(n%2)cout << "No" << endl;
    else
    {
        if(s.substr(0,n/2)==s.substr(n/2,n/2))cout << "Yes" << endl;
        else cout <<"No"<< endl;    }
}
