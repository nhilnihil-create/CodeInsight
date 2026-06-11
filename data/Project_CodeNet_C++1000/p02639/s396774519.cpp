#include <bits/stdc++.h>
 
using namespace std;
 
int main()
{
    int ar[5];
    for(int i=0; i<5; i++)
    {
        cin>>ar[i];
    }
    for(int i=0; i<5; i++)
    {
        if(ar[i]==0)
        {
            cout<<i+1<<endl;
        }
    }
    return 0;
}