#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin>>n;
    char a[n];
    char ch;
    for(int i=0;i<n;i++)
     {cin>>a[i];}
    int i=0,j=n-1,c=0;
    while(i<j)
    {
        if(a[i]=='W' && a[j]=='R')
        {
            swap(a[i],a[j]);
            i++;j--;
            c++;
        }
       else if(a[j]=='W')
        j--;
       else if(a[i]=='R')
        i++;
       
        
    }
    if(i==j && n%2!=0 && i==n/2+1 && a[i]=='W')
     c++;
    cout<<c<<endl;

}