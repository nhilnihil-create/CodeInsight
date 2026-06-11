#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin>>n;
    int A[100][2];
    for(int i=0;i<n;i++)
        cin>>A[i][0]>>A[i][1];

    long long int cnt=0;
    for(int i=0;i<n-2;i++)
    {
        if(A[i][0]==A[i][1] && A[i+1][0]==A[i+1][1] &&A[i+2][0]==A[i+2][1])
         {
             cout<<"Yes\n";
             return 0;
         }
    }
        cout<<"No\n";

}
