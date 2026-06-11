#include <iostream>
#include <cstring>
#include<vector>
#include <algorithm>
#include<cstdlib>
#include<math.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<n;i++)

int main()
{
   
    string s;
    int k;
    cin >> k >> s;
    if (s.size() <= k)
    {
        cout << s << "\n";
    }
    else
    {
        rep(i, k) cout << s[i];
        cout << "..." << "\n";
    }


    return 0;
}