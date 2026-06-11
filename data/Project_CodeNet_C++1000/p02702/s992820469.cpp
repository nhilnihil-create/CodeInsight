#include<bits/stdc++.h>
using namespace std;
#define int long long int 
int mod = 2019;

int32_t main()
{
    string s;
    cin >> s;
    int n = s.length();
    unordered_map<int, int> ump;

    ump[0] = 1;
    int ans = 0;
    int powerOfTen = 1;
    int currentValue = 0;
    for(int i=n-1; i>=0; i--)
    {
        int curDigit = s[i] - '0';
        currentValue = (currentValue + curDigit * powerOfTen ) % mod;
        powerOfTen = (powerOfTen * 10 ) % mod;
        ans += ump[currentValue];
        ump[currentValue]++;
    }
    
    cout << ans << endl;
    return 0;
}