#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int N, A, B, C, D;
    cin >> N >> A >> B >> C >> D;
    A--; B--; C--; D--;
    string S;
    cin >> S;

    if(C > D)
    {
        int cnt = 0;
        for(int i=B-1; i<=D+1; i++)
        {
            if(S[i] == '.') cnt++;
            else cnt = 0;
            if(cnt == 3) break;
        }
        if(cnt != 3)
        {
            cout << "No\n";
            return 0;
        }
    }
    int iwa = 0;
    for(int i=0; i<S.size(); i++)
    {
        if(S[i] == '#') iwa++;
        else iwa = 0;
        if(iwa >= 2)
        {
            if((A<=i && i<=C) || (B<=i && i<=D))
            {
                cout << "No\n";
                return 0;
            }
        }
    }

    cout << "Yes\n";

    return 0;
}
