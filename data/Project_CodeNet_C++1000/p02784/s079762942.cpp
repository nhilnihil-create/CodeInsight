#include<iostream>
using namespace std;
int main ()
{
    long long int n,m,a,i;
long long    int sum=0,sum1=0,sum2=0;
    cin>>n;
    cin>>m;
 long long   int arr[m];
    for (int i=0; i<m; i++)
    {
        cin>>arr[i];
    }
    for (int i=0; i<m; i++)
    {
        if(i%2==0)
        {
            sum1=sum1+arr[i];
        }
        if (i%2==1)
        {
            sum2=sum2+arr[i];
        }
        sum=sum +arr[i];

    }

    if (sum>=n || sum1>=n || sum2>=n)
        cout<<"Yes"<<endl;
    else
        cout<<"No"<<endl;
    return 0;
}
