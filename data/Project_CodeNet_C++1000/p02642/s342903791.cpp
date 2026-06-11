#include <iostream>

using namespace std;
int frecv[1000001],n,x,v[200001],sol,ok;
int main()
{
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> v[i];
        ++frecv[v[i]];
    }
    if(frecv[1] > 1) sol = 0;
    else if(frecv[1] == 1) sol = 1;
    else
    {
        for(int i = 1; i <= n; ++i)
        {
            ok = 1;
            if(frecv[v[i]] > 1) ok = 0;
            else
            {
                for(int j = 2; j*j <= v[i]; ++j)
                {
                    if(v[i] % j == 0 && frecv[j] >= 1)
                        ok = 0;
                    if(v[i] % (v[i]/j) == 0 && frecv[v[i]/j] >= 1)
                        ok = 0;
                }
            }
            sol += ok;
        }
    }
    cout << sol << " ";
    return 0;
}
