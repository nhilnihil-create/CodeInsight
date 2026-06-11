#include <iostream>
using namespace std;
int main()
{
    int n,k,count=0;
    cin>>n>>k;
    int a[100000];
    char temp;
    for(int i=0;i!=n;i++)
    {
        cin>>temp;
        if(temp=='L')
        {
            a[i]=-1;
        }
        else a[i]=1;
    }
    temp=a[0];
    for(int i=0;i<n&&k!=0;)
    {
        while(a[i]==temp&&i<n)
        {
            if(count%2)
            {
                a[i]*=(-1);
            }
            i++;
        }
        if(count%2)
        {
            k--;
        }
        count++;
        if(i<n) temp=a[i];
    }
    count=0;
    for(int i=0;i<n;i++)
    {
        if(i==0&&a[i]==-1) continue;
        if(i==n-1&&a[i]==1) continue;
        count+=int(a[i+a[i]]==a[i]);
    }
    cout<<count;
}
