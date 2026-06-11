#include<bits/stdc++.h>
using namespace std;
#define fraction() cout.unsetf(ios::floatfield); cout.precision(10); cout.setf(ios::fixed,ios::floatfield);
#define file() freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);
#define faster() ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define endl '\n'
#define mx_int_prime 999999937
#define mem(a,b) memset(a, b, sizeof(a) )
#define PB push_back
#define F first
#define S second
#define all(a) (a).begin(),(a).end()
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
    faster();
    vector<int> v1,v2,v3;
    int n,y,z;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        v1.PB(x);
        v3.PB(x);
    }
    sort(all(v3));
    for(int i=0; i<n; i++)
    {
        int x;
        cin>>x;
        v2.PB(x);
    }
    int cnt=1,flag=0;
    do
    {
        if(v1==v3)
        {
            y=cnt;
            flag++;
        }
        if(v2==v3)
        {
            z=cnt;
            flag++;
        }
        cnt++;
        if(flag==2)
            break;
    }
    while(next_permutation(all(v3)));
    cout<<abs(y-z)<<'\n';

}
