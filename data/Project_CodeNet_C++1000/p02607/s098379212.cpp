#include <iostream>

using namespace std;

int main()
{
    int n,s=0 ; cin>>n;
    int arr[n] ;
    for (int i=0 ; i<n ;i++) {
        cin>>arr[i] ;
    }
    for (int j=0 ; j<n ;j=j+2) {
        if (arr[j]%2!=0) s =s +1 ;
    }
    cout<<s ;
    return 0;
}
