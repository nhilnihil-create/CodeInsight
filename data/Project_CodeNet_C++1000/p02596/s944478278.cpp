#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    long long seven = 7;
    set<long long> seven_set;
    int ans = 1;
    while (seven % n != 0)
    {
        seven = (seven % n) * 10 + 7;
        if(seven_set.count(seven % n))
        {
            ans = -1;
            break;
        }
        else
        {
            seven_set.insert(seven % n);
        }
        
        ans ++;
    }

    cout << ans << endl;
}