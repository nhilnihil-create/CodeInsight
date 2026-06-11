#include <bits/stdc++.h>
#define fto(i,a,b) for(int i=a; i<=b; ++i)
#define fdto(i,a,b) for(int i=a; i>=b; --i)
#define pb push_back
#define ll long long
#define pii pair<int,int>
#define st first
#define nd second
#define maxn
#define Ntu "bai1"

using namespace std;
int m,d;
bool kt(int z)
{
    while (z>0)
    {
        if (z%10<2) return false;
        z/=10;
    }
    return true;
}
int main()
{
    ios_base::sync_with_stdio(0);
    //freopen(Ntu".inp","r",stdin);
    //freopen(Ntu".out","w",stdout);
    cin.tie(NULL);cout.tie(NULL);
    cin >> m >> d;
    int rs=0;
    int x,y;
    fto(i,1,m)
    fto(j,10,d)
    {
        if (!kt(j)) continue;
        x=j;y=1;
        while (x>0) y*=x%10,x/=10;
        if (y==i) ++rs;
    }
    cout << rs;
    return 0;
}
