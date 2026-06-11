#include <iostream>

using namespace std;

int main()
{
    int n,temp,x=0,k;
    cin>>n>>k;
    int arr[n];
    for (int i=0;i<n;i++){
        cin>>arr[i];
    }
    for (int i=0;i<n;i++){
        for( int j=i+1;j<n;j++){
                if(arr[i]>arr[j]){
                    temp=arr[i];
                    arr[i]=arr[j];
                    arr[j]=temp;
        }}
    }
  for(int i=0;i<k;i++){
    x+=arr[i];
  }
  cout<<x;
    return 0;
}
