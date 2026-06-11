#include <bits/stdc++.h>
#define Tayeb ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL)
using namespace std;
int main()
{
    Tayeb;
    int count=0;
    string S;
    cin >> S;
    for(int i=0; i<S.length(); i++)
    {
        if(S[i]=='R'&&S[i+1]=='R'&&S[i+2]=='R')
        {
            count=3;
            break;
        }
        else if(S[i]=='R'&&S[i+1]=='R')
        {
            count=2;
            break;
        }

        else if(S[i]=='R')
        count=1;
    }
    cout << count << "\n";

    return 0;

}
