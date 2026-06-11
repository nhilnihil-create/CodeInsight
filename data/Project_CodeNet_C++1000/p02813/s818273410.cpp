#include <bits/stdc++.h>
#define int long long
#define gcd            __gcd
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define deci(x,y)      fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI             3.141592653589793238
using namespace std;

int power(int x, int y, int p)
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}
int modi(int a, int m)
{
    return power(a, m - 2, m);
}
int32_t main()
{
    nitin;
    int n;
    cin>>n;
    vector<int>a(n);
    vector<int>b(n);
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    for(int j=0;j<n;j++){
        cin>>b[j];
    }
    bool flag=true;
    for(int i=0;i<n;i++)
    {
        if(a[i]>b[i])
        {
            flag=true;
            break;
        }
        else if(a[i]<b[i]){
            flag=false;
            break;
        }
    }
    if(flag)
    {
        swap(a,b);
    }
    int cnt=0;
    do{
        if(a==b)
            break;
        else
            cnt++;
    }
    while(next_permutation(a.begin(),a.end()));
    cout<<cnt<<endl;
    return 0;

}