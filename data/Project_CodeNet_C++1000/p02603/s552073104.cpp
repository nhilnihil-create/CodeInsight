#include<iostream>
using namespace std;

long long int BuyStock(long long int i, long long int arr[], long long int N)
{
    long long int j;
    for(j=i;j<N-1;j+=1)
    {
        if(arr[j]<arr[j+1])
        {
            return(j);
        }
    }
    return(N-1);
}

long long int SellStock(long long int i, long long int arr[], long long int N)
{
    long long int j;
    for(j=i;j<N-1;j+=1)
    {
        if(arr[j]>arr[j+1])
        {
            return(j);
        }
    }
    return(N-1);
}


int main()
{
    long long int N, i, arr[85], temp, buy, sell, stock=0, amount=1000;
    cin>>N;
    for(i=0;i<N;i+=1)
    {
        cin>>arr[i];
    }
    i = 0;
    while(i<N)
    {
        buy = BuyStock(i, arr, N);
        if(buy==N-1)
        {
            break;
        }
        sell = SellStock(buy+1, arr, N);
        stock = amount/arr[buy];
        amount = amount%arr[buy];
        amount = amount+stock*arr[sell];
        stock = 0;
        i = sell+1;
    }
    cout<<amount<<endl;
}