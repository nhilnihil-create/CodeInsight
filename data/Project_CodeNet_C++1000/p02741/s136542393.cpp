#include<bits/stdc++.h>
using namespace std;
int main()
{
    int i,j,k,ar[32]= {1,1,1,2,1,2,1,5,2,2,1,5,1,2,1,14,1,5,1,5,2,2,1,15,2,2,5,4,1,4,1,51};
    cin>>k;
    for(i=0; i<=32; i++)
    {

        if(i==(k-1))

            cout<<ar[i];

    }
    return 0;
}
