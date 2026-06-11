/*;

THE BEST IS YET TO COME
*/
#include <bits/stdc++.h>
using namespace std;
#define r(i, s, l) for (int i = s; i < l; i++)
#define rr(i,s,l) for(int i=s;i>=l;i--)
#define mod 1000000007
#define int long long
#define INT_BITS 32
#define ld long double
#define pp pair<int,int>
#define ss second
#define ff first
#define INF 1e18
#define N 2000005
#define all(a) a.begin(), a.end()
#define pb push_back
#define endl "\n"
using namespace std;
void fast()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
}

signed main()
{


    int n,l;
    cin>>n>>l;

    int sum = 0;
    int diff = INT_MAX;

    vector<int> a(n);
    r(i,0,n)
    {
        a[i] = i+1;
        a[i] = l+i;
        sum += a[i];

    }

    int ans;
    r(i,0,n)
    {
          int sum2 = 0;
          r(j,0,n)
          {
              if(i!=j)
              sum2 += a[j];
          }

          if(abs(sum2-sum)<diff)
          {
              diff = abs(sum2 - sum);
              ans = sum2;
          }

    }

    cout<<ans;





	return 0;
}

