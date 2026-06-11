#include<iostream>
using namespace std;
#define selling true
#define buying false
typedef long long int ll;
int main()
{
    int n;
    cin>>n;
    ll a[n];
    ll money = 1000,stock = 0;
    bool status = buying;
    for(int i=0;i<n;i++)
    cin>>a[i];
    int i=0,j;
    while(i<n)
    {
        j=i;
        if(status==buying)
        {
            while(j<n-1 & a[j]>=a[j+1])
                j++;
            if(j==n-1)
            break;
            //cout<<"Buying at "<<j+1<<endl;
            stock = money/a[j];
            money = money%a[j];
            status=selling;
        }
        else if(status == selling)
        {
            while(j<n-1 && a[j]<=a[j+1])
                j++;
            money = money+a[j]*stock;
            //cout<<"Selling at "<<j+1<<endl;
            status = buying;
        }
        i = j+1;
    }
    cout<<money<<endl;
}