#include <bits/stdc++.h>
typedef long long ll;
#define MOD 1000000007
#define INF -99999999 
using namespace std;
 
int main()
{
    int A,B,M; cin >> A >> B >> M;
    int a[A],b[B],mina,minb;
    mina = minb = 1000000;
    for (int i = 0; i < A; i++)
    {
        cin >> a[i];
        mina = min(mina,a[i]);
    }
    for (int i = 0; i < B; i++)
    {
        cin >> b[i];
        minb = min(minb,b[i]);
    }
    int ans = mina+minb;
    for (int i = 0; i < M; i++)
    {
        int x,y,c;
        cin >> x >> y >> c;
        ans = min(ans,a[x-1]+b[y-1]-c);
    }
    cout << ans << endl;

}