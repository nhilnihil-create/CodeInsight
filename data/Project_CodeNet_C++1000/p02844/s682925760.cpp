#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N;
    cin >> N;
    string S;
    cin >> S;

    int ans = 0;
    for(char i='0'; i<='9'; i++)
    {
        auto itr_i = S.find(i);
        if(itr_i == string::npos) continue;
        for(char j='0'; j<='9'; j++)
        {
            auto itr_j = S.find(j, itr_i+1);
            if(itr_j == string::npos) continue;
            for(char k='0'; k<='9'; k++)
            {
                if(S.find(k, itr_j+1) != string::npos)
                {
                    ans++;
                }
            }
        }
    }
    cout << ans << endl;

    return 0;
}