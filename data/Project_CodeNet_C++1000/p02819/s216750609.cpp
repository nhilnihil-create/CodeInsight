#include <bits/stdc++.h>
using namespace std;

int main()
{
    cin.tie(0);
    ios::sync_with_stdio(0);

    int x;
    cin>>x;

    if(x==2)
    {
        cout<<2<<"\n";
        return 0;
    }

    if(x%2==0)x++;

    for(;;x+=2)
    {
        int max=sqrt(x);

        bool prime=true;
        for(int i=2;i<=max;i++)
        {
            if(x%i==0)
            {
                prime=false;
                break;
            }
        }
        if(prime)break;
    }

    cout<<x<<"\n";

    return 0;
}
