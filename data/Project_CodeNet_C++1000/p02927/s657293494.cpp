#include <bits/stdc++.h>
#define VanLoi "bai1"
#define f first
#define s second
#define fi(a,b,c) for( int a= b; a<= c;++a)
#define fid(a,b,c) for( int a= b; a>= c;--a)
#define pii pair< int, int>
#define ll long long
#define pb push_back
#define getbit(x,i) (x>>i&1)
#define maxn 100005
#define oo 1e18

using namespace std;

int M, D, res = 0;

int main()
{
    ios_base:: sync_with_stdio(0);
    //freopen(VanLoi".inp","r",stdin);
    //freopen(VanLoi".out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    cin >> M >> D;
    fi(i, 1, M)
        fi(j, 1, D){
            int d1 = j / 10, d2 = j % 10;
            if (d1 >= 2 && d2 >= 2 && d1 * d2 == i) res++;
        }
    cout << res;
}
