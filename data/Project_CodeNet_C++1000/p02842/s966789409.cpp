#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

#define fast                        \
  ios_base::sync_with_stdio(false); \
  cin.tie(NULL);

void start()
{
    fast;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
}
/***********************************************************************************************************/

int main()
{
    start();

    int n;
    cin>>n;

    double x;

    for (int i=1;i<=n;i++)
    {
        x=i*1.08;
        if ((int)x==n)
        {
            cout<<i;
            return 0;
        }
    }
    cout << ":(";

    return 0;
}
