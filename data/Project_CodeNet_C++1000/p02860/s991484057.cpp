
#include<bits/stdc++.h>

using namespace std;

#define ios         ios_base::sync_with_stdio(false);
#define ll          long long
#define ld          long double
#define db(x)       cout << "[" << #x << ": " << (x) << "]\n"
#define db2(x,y)    cout << "[" << #x << ": " << (x) << "]  [" << #y << ": " << (y) << "]\n"
#define db3(x,y,z)  cout << "[" << #x << ": " << (x) << "]  [" << #y << ": " << (y) << "]  [" << #z << ": " << (z) << "]\n"
#define cn          107
#define sn          1007
#define bn          200007
#define M           1000000007
#define inf         LLONG_MAX



int main()
{
        ios;
        ll n; cin >> n;
        string s; cin >> s;
        if(n%2) { cout << "No"; exit(0);}
        for(ll i = 0; i < n/2; i++)
        {
                if(s[i] == s[i+n/2]) continue;
                cout << "No"; exit(0);
        }
        cout << "Yes";
}

