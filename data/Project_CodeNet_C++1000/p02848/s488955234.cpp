#include<bits/stdc++.h>
using namespace std;
int main()
{
    string S;
    int n;

    cin >> n;
    cin >> S;
    int len = S.size();
    for(int i = 0; i < len; i++)
    {
        /*while(n--)
        {
            S[i] = S[i]+ 1;
            if(S[i] == 'Z')
            {
                S[i]
            }
        }*/
        S[i] = S[i] + n;
        if(S[i] <= 'Z')
        {
            cout << S[i];
        }
        else
        {
            int x = S[i] - 'Z';
            S[i] = 64 + x;
            cout << S[i];
        }
        
    }
    cout << endl;
}


