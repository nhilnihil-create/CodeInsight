#include<bits/stdc++.h>

using namespace std;

int main()
{
    int arr[21],n,c=0;


    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=1;i<n-1;i++){
        if((arr[i]>arr[i-1] && arr[i]<arr[i+1])|| (arr[i]<arr[i-1] && arr[i]>arr[i+1])){
            c++;
        }
    }

    cout<<c<<endl;
}
