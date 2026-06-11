#include <iostream>

using namespace std;

int main()
{
    int n,x=0;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<n;i++){
        if(i%2==0 && arr[i]%2==1)
            x+=1;
    }
    cout<<x;
    return 0;
}
