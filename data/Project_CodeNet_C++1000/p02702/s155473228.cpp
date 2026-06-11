#include <bits/stdc++.h>
using namespace std;

void Main()
{
    string s;
    cin >> s;
    vector<int> sm(s.size()+1); // sの下i桁の数 % 2019
    vector<int> cm(2019); // i = sの下i桁の数 % 2019 となる数
    sm[0] = 0;
    cm[0] = 1;
    int e = 1;
    for (int i = 1; i <= s.size(); i++)
    {
        sm[i] = (((s[s.size()-i] - '0') * e) % 2019 + sm[i-1]) % 2019;
        cm[sm[i]]++;
        e = (e * 10) % 2019;
    }
    int sum = 0;
    for (int i = 0; i < 2019; i++)
    {
        // if(cm[i] > 0)
        //     cout << i << " " << cm[i] << endl;
        if(cm[i] >= 2)
            sum += cm[i] * (cm[i]-1) / 2;
    }
    cout << sum << endl;

    // s[i..j] % 2019 == 0
    // (s[i..n] - s[j..n]) / 10^(n-j) % 2019 == 0
    // (s[i..n] % 2019) - (s[j..n] % 2019) == 0
    // s[i..n] % 2019 = s[j..n] % 2019
    
}

int main(int argc, char **argv)
{
    Main();
    return 0;
}
