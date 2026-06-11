#include <bits/stdc++.h>
using namespace std;
int main()
{
    int K,X;
    cin >> K >> X;
    int count=1;
    while(1)
    {

        cout << X-K+count << " ";
        count++;
        if(count==2*K)
        {
            break;
        }
    }
    cout << endl;
    
}