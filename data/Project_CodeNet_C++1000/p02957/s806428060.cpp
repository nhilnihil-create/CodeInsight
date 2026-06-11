#include<bits/stdc++.h>

using namespace std;



int main()
{
    long long a,b,p;

    cin >> a >>  b;

    long long k;

    k=min(a,b);

    p=abs(a-b);



    if(p%2!=0)
    {
        cout << "IMPOSSIBLE";
    }
    else
    {
        p=p/2;

        cout << k+p;
    }


    return 0;
}