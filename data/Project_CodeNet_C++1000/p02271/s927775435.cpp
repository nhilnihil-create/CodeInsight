#include<iostream>
using namespace std;

int A[50],n;
int solve(int i,int m)
{
    if(m==0)
        return 1;
    if(i>=n)
        return 0;
    return solve(i+1,m)||solve(i+1,m-A[i]);
}

int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
    }

    int q,x;
    cin>>q;
     for(int i=0;i<q;i++)
    {
        cin>>x;
        if(solve(0,x))cout<<"yes\n";
        else cout<<"no\n";
    }
    return 0;

}