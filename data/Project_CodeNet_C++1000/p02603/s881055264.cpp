//2020-07-31
#include <bits/stdc++.h>
using namespace std;
#define loop(v, st, en) for (int v = st; v < en; v++)
#define loopdesc(v, st, en) for (int v = st; v >= en; v--)
#define INF 1E9
#define clr(v, d) memset(v, d, sizeof(v))
#define P(x) cout << #x << " = { " << x << " }\n"
#define PI acos(-1)

typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
const int M = 2e5 + 5;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n, cur = 300, total = 1000, stock = 0, s = -1, b = -1;
    cin >> n;
    ll arr[n+5];

    loop(i, 0, n) cin >> arr[i];
    loop(i, 0, n)
    {
        
        if (b == -1)
        {
            if (arr[i] <= cur)
                cur = arr[i];
            else
                b = cur;
        }
        if(b!=-1){
            if(arr[i]>=cur)cur= arr[i];
            else 
            s= cur ;
            if(i==n-1&& cur>b)s=cur;
        }
        if(s!=-1 &&b!= -1){
            stock = total / b ; 
            total -= stock * b;
            total += stock *s ; 
            stock =0 ;
            b=-1;
            s=-1;
            i--;
            cur =300;
        }
    }
    
    cout<<total <<endl;
    return 0;
}