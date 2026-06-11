#include<bits/stdc++.h>
using namespace std;
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define optimize() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define mx_int_prime 999999937
#define mem(a,b) memset(a, b, sizeof(a) )
typedef long long ll;
typedef long double ld;
const int mx=2e5+125;
const double PI = acos(-1);
const double eps = 1e-9;
const int inf = 2000000000;
const ll infLL = 9000000000000000000;
ll p[mx],a[mx],b[mx];
int main()
{
    optimize();
    int k,x;
    cin>>k>>x;
    int ans=k*500;
    if(ans>=x)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;


    return 0;
}
