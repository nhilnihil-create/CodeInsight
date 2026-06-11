#include <bits/stdc++.h>

using namespace std;

int k,a,b,c;

int main()
{
    cin>>a>>b>>c>>k;
    for (int i=0;i<=k;++i)
    {
        for (int j=0;j+i<=k;++j)
        {
            if (a<(b*(1<<i)) && (b*(1<<i))<(c*(1<<j)))
            {
                cout<<"Yes";
                return 0;
            }
        }
    }
    cout<<"No";
    return 0;
}
