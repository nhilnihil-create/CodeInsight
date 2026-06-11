#include<bits/stdc++.h>
using namespace std;
int main()
{
    int N;
    cin>>N;
    int A[N+1];
    int s=0;
 
    for(int i=1;i<=N;i++)
    {
        cin>>A[i];
 }
 
    for(int i=1;i<=N;i++)
    {
        for(int j=i+1;j<=N;j++)
        {
            s+=A[i]*A[j];
        }
    }
 
    cout<<s;
 return 0;
}