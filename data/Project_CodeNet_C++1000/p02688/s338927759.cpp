#include <iostream>
using namespace std;
int main()
{
    int n,k;
    cin>>n>>k;
    int A[n]={};
    for(int i=0;i<k;i++)
    {
        int d;
        cin>>d;
        int b[d];
        for(int i=0;i<d;i++)
        {
        cin>>b[i];
        A[b[i]-1]=1;
        }
    }
    int count=0;
    for(int i=0;i<n;i++)
    {
        if(A[i]==0)
        count++;
    }
    cout<<count<<endl;
    return 0;
}
