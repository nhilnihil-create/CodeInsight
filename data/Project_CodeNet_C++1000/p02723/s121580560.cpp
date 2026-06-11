#include<bits/stdc++.h>
using namespace std ;
typedef long long ll;
#define cf ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0)
#define fox(i,j,n) for( i=j;i<n;i++)
#define srtar(a,n) sort(a,a+n)
#define srtvec(v) sort(v.begin(),v.end())
#define fauto(x,t) for(auto x: t)
#define mem(n,x) memset(n, x, sizeof(n))
const double pi=acos(-1);

int main()
{
    int t, i ;
    string s;
    cin >> s;
    if(s[3]==s[2] && s[4]==s[5])
        cout << "Yes";
    else
        cout << "No";
    return 0;
}