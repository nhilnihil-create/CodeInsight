#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main()
{
    int A[5];
    for(int i=0;i<5;i++)
    {
        cin>>A[i];
        if(A[i]==0)
        {
            cout<<i+1<<endl;
            break;
        }
    }
    return 0;
}
