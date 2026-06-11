#include <iostream>
#include <climits>

using namespace std;

int main(int argc, char const *argv[])
{
    long long L, R;
    cin >> L >> R;
    long long ans;
    for (int i = L; i <= R; i++)
    {
        if (i % 2019 == 0)
        {
            ans = 0;
            cout << ans << endl;
            return 0;
        }
        
    }

    long long mod;
    long long modmin = __LONG_LONG_MAX__;
    for (int i = L; i <= R - 1; i++)
    {
        for (int j = i + 1; j <= R; j++)
        {
            mod = ((i % 2019) * (j % 2019)) % 2019;
            if (mod < modmin) modmin = mod;
        }
        
    }

    cout << modmin << endl;
    
    return 0;
}