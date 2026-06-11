#include <iostream>
#include <algorithm>
using namespace std;
int arr[1001];
int main()
{
    int n=0,quan=0;
    cin>>n;
    cin>>quan;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    int sum=0;
    for(int i=0;i<quan;i++){
        sum+=arr[i];
    }
cout<<sum;
    return 0;
}
