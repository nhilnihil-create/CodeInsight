#include<bits/stdc++.h>
using namespace std;
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
const long long int infLL = 9000000000000000000;
#define mem(a,b) memset(a, b, sizeof(a) )
#define all(a) (a).begin(),(a).end()
#define mx_int_prime 999999937
const int inf = 2000000000;
const double PI = acos(-1);
const double eps = 1e-9;
typedef long double ld;
#define MOD 1000000007
typedef long long ll;
const int mx=2e5+125;
ll p[mx],a[mx],b[mx];
#define PB push_back
#define endl '\n'
#define S second
#define F first
int main()
{
    faster();
    string s,t,u;
    cin>>s>>t;
    int a,b;
    cin>>a>>b;
    cin>>u;
    int len1=s.size();
    int len2=t.size();
    if(s==u)
        cout<<a-1<<" "<<b<<endl;
    else
        cout<<a<<" "<<b-1<<endl;
    return  0;
}
