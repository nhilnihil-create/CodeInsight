#include<bits/stdc++.h>

using namespace std;

int main()
{   

    string s;
    cin>>s;
    int ans = 0;
    int suf = 0;
    vector<int> count_suf(2019);
    count_suf[suf]++;
    int big = 2019;
    int power = 1;
    for(int i = s.length()-1;i>=0;i--)
    {
        int digit = s[i]-'0';
        suf = (suf + digit * power) % big;
        power = power * 10 % big;
        ans += count_suf[suf];
        count_suf[suf]++;
    }

    cout<<ans;


    return 0;
}