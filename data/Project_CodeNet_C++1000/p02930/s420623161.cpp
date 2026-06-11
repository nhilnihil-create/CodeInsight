#include <bits/stdc++.h>
#define fto(i,a,b) for(int i=a; i<=b; ++i)
#define fdto(i,a,b) for(int i=a; i>=b; --i)
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define st first
#define nd second
#define maxn
#define Ntu ""

using namespace std;
int n;
int main()
{
    ios_base::sync_with_stdio(0);
    //freopen(Ntu".inp","r",stdin);
    //freopen(Ntu".out","w",stdout);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n;
    fto(i,1,n)
    fto(j,i+1,n)
    {
        for(int o=0; (1<<o)<=n; ++o) if((i&(1<<o)) != (j&(1<<o)))
        {
            cout << o+1;
            break;
        }
        if(j == n) cout << '\n';
        else cout << ' ';
    }
    return 0;
}
