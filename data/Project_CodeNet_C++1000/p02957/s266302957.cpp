#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long int a,b,k=0,c=0;
    cin >> a >> b;
    while(k<=a || k<=b)
    {
        if(abs(a-k)==abs(b-k))
        {
            c++;break;
        }
        k++;
    }
    if(c!=0)
        cout << k << endl;
    else
        cout << "IMPOSSIBLE" << endl;
    return 0;
}
