#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main()
{
    string S, T;
    cin >> S;
    cin >> T;
    int def;

    int ans = T.size();

    for(int temp = 0; temp <= S.size() - T.size(); temp++)
    {
        def = 0;
        for(int i =0; i < T.size(); i++)
        {
            if(T[i] != S[temp + i])
                def++;
        }
        ans = min(ans, def);
    }

    cout << ans << "\n";
}