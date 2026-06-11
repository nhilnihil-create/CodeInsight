#include <bits/stdc++.h>
#define int long long int
#define gif(a,b) (a/b +(a%b?1:0))
#define watch(x) cout<<(#x)<<" is "<<(x)<<"\n";
using namespace std;

int32_t main()
{   
    cin.tie(NULL);
    std::ios::sync_with_stdio(false);
   
   int s, t;
   cin >> s >> t;
   if(s <= t)
  	cout << "unsafe";
   else
   cout << "safe";
    return 0;
}
