#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0; i<(n); ++i)
#define outl(x) cout<< (x) << '\n'
using namespace std;
using pii = pair<int,int>;
using ll = long long;
vector<int> G;

ll insertion(int a[], int n, int g)
{
    ll cnt = 0;
    for (int i=g; i < n; ++i) {
        int j = i-g;
        int tmp = a[i];

        while (j >= 0 && a[j] > tmp) {
            a[j+g] = a[j];
            j -= g;
            ++cnt;
        }
        a[j+g] = tmp;
    }
    return (cnt);
}

ll shell(int a[], int n)
{
    int h = 1;
    ll cnt = 0;
     while (h <= n) {
         G.push_back(h);
         h = 3*h + 1;
     }

     for (int i=G.size()-1 ; i >= 0; --i) {
         cnt += insertion(a, n, G[i]);
     }

     return cnt;
}

signed main()
{
   cin.tie(0), ios::sync_with_stdio(false);

   int n;
   int a[1000123];

   cin >> n;
   rep(i, n) cin >> a[i];

   ll cnt = shell(a, n);

   outl(G.size());
   for (int i=G.size()-1; i >= 0; --i) {
       cout << G[i] << (i-1 >= 0 ? ' ' : '\n');
   }
   outl(cnt);

   rep(i, n) {
       outl(a[i]);
   }
}


