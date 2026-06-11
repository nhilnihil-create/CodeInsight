#include <bits/stdc++.h>
using namespace std;
#define int long long

int32_t main()
{
    
    int t;
    cin >> t;
    int o = t%10;
    if(o == 3)
     cout << "bon" << "\n";
    else if(o == 0 || o == 1 || o == 6 || o == 8 )
     cout << "pon" << "\n";
    else
      cout << "hon" << "\n";
    return 0;
}
