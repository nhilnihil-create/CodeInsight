#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int n,m ; cin>> n>>m ;
    int sum =0 ;
    int arr[n] ;
    for (int i=0 ; i<n ; i++) {
        cin>>arr[i] ;
    }
   for (int r=0 ; r<n ; r++) {
    for (int j=0 ; j<n-1 ; j++) {
        if (arr[j]>arr[j+1]) {
            int Swap = arr[j] ;
            arr[j] = arr[j+1] ;
            arr[j+1]=Swap ;
        }
         }
       }

    for (int i=0 ; i<m ;i++) {
        sum = arr[i] + sum ;
    }
    cout<<sum ;


    return 0;
}
