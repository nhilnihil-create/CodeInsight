#include <iostream>

using namespace std;

int main()
{
    int n ,c=0;
    cin>>n;
    int arr[n];
    for(int i=0 ; i<n ; i++){
        cin>>arr[i];
    }
    for(int i=1 ; i<n+1 ; i+=2){
        if(arr[i-1]%2==1){
            c++;
        }
    }
    cout<<c;
    return 0;
}

