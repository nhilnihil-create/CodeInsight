#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    
    for(int i = -200; i <= 200; ++i)
    {
        ll a = 1LL;
        
        for(int k = 0; k < 5; ++k)
        {
            a *= (ll)i;   
        }
        
        for(int j = -200; j <= 200; ++j)
        {
               ll b = 1LL;
               
               for(int k = 0; k < 5; ++k)
               {
                    b *= (ll)j;
               }
               
               if(a - b == n)
               {
                    cout << i << ' ' << j << '\n';
                    return 0;
               }
        }
    }
}