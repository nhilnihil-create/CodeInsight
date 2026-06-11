

#include<bits/stdc++.h>

using namespace std;

int main()
{
    int i,j,n,k;

    while(cin >> n >> k)
    {
        if(k==1)
            cout << 0 << endl;
        else
            cout << abs(n-k) << endl;
    }

    return 0;
}
