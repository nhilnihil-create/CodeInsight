#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;

    cin >> n;

    bool flg=0;

    while(n!=0)
    {
        if(n%10==7)
        {
            flg=1;
            cout << "Yes" << endl;
            break;

        }

        n=n/10;

    }

    if(flg==0)
    {
        cout << "No" <<endl;
    }
    return 0;
}
