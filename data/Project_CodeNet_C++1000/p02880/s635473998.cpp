#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>> n;

    bool x = false;
    for(int i = 1; i <= 9; i++)
    {
        if(n % i == 0)
        {
            int temp = n/i;
            if(temp <= 9)
            {
                cout<< "Yes\n";
                x = true;
                break;
            }
        }
    }
    if(!x)
        cout<< "No\n";

    return 0;
}
