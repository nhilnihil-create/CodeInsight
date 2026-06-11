#include <bits/stdc++.h>
using namespace std;
#define int long long
#define mod 1000000007
#define deb(x) cerr << "\n" \
                    << #x << "=" << x << "\n";
#define deb2(x, y) cerr << "\n"                   \
                        << #x << "=" << x << "\n" \
                        << #y << "=" << y << "\n";
#define w(x)  \
    int x;    \
    cin >> x; \
    while (x--)

int32_t main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int n;
    cin>>n;
    vector<pair<int,int>>v(n-1);
    for(auto &i:v){
      int x,y;
      cin>>x>>y;
      i.first = min(x,y);
      i.second = max(x,y);
    }
    int ans = 0;
    for(int i=0;i<n;i++)
      ans += (i+1)*(n-i);

    for(auto i:v)
      ans -= (n-i.second+1)*(i.first);

    cout<<ans;


}    
