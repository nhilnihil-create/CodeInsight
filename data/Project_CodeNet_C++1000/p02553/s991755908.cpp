#include<bits/stdc++.h>

using namespace std;

#define ios         ios_base::sync_with_stdio(false);
#define ll          long long
#define ld          long double
#define db(x)       cout << "[" << #x << ": " << (x) << "]\n"
#define db2(x,y)    cout << "[" << #x << ": " << (x) << "]  [" << #y << ": " << (y) << "]\n"
#define db3(x,y,z)  cout << "[" << #x << ": " << (x) << "]  [" << #y << ": " << (y) << "]  [" << #z << ": " << (z) << "]\n"
#define cn          23
#define sn          1007
#define bn          200007
#define M           100000007
#define inf         LLONG_MAX


int main()
{
        ios;
        ll a,b,c,d; cin >> a >> b >> c >> d;
        ll ac = a*c, ad = a*d, bc = b*c, bd = b*d;
        cout << max(max(max(ac,ad),bc),bd);
}
