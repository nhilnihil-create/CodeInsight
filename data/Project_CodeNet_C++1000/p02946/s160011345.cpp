#include<bits/stdc++.h>
#include<cmath>

using namespace std;
typedef long long li;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(false);

    int k,x;
    cin>>k>>x;

    li from = max(-1000000, x - k + 1), to = min(1000000, x + k -1);
    for( int i = from; i <= to; ++i)
    {
        cout << i;
        if(i == to)
        {
            cout<<"\n";
        }
        else { cout << " ";}
    }

    return 0;
}

