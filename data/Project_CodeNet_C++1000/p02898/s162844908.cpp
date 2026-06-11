//SAIKH SERAJ FAHIM, CSE-19-HSTU, BANGLADESH.

#include<iostream>
using namespace std;
int main()
{
    int n,k,i,count=0;
    cin>>n>>k;
    int ar[100000];
    for(i=0; i<n; i++)
        cin>>ar[i];
    for(i=0; i<n; i++)
    {
        if(ar[i]>=k)
            count++;
    }
    cout<<count<<endl;
    return 0;
}