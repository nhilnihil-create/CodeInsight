#include <bits/stdc++.h>
#define fto(i,j,h)   for (int i=j; i<=h; i++)
#define fdto(i,j,h)  for (int i=j; i>=h; i--)
#define ANH BAI1
#define maxn 109
#define ll long long
using namespace std;

int m, d;
int main()
{
    //freopen("ANH.inp", "r", stdin);
    //freopen("ANH.out", "w", stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin >> m >> d;
    int res = 0;
    fto(i,1,m)
      fto(j,1,d){
          int t1 = j/10,  t2 = j%10;
          if (t1 >= 2 && t2 >= 2 && t1*t2 == i)    ++res;
      }
    cout << res;
}
