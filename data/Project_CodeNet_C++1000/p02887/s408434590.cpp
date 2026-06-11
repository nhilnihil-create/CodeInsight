#include<iostream>
using namespace std;
int main()
{
    int n;
    int count=0;
    cin>>n;
    char ar[100000];
    for(int i=0; i<n; i++)
    {
        cin>>ar[i];
    }
    for(int i=0; i<n; i++)
    {
        if(ar[i]==ar[i+1])
        {
            continue;
        }
        count++;
    }
    cout<<count;
}
