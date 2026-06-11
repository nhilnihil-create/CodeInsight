#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n , summ=0 , k;
    cin>>n>>k;
    int arr[n];
    for( int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    sort(arr,arr+n);
    for(int i=0 ; i<k ; i++){
        summ+=arr[i];
    }
    cout<<summ;
    return 0;
}
