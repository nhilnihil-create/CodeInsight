#include <iostream>
#include<bits/stdc++.h>

using namespace std;

int main()
{
    int n;cin>>n;
    int arr[n];
    int ans=0;
    for(int i = 0;i<n;i++)
    {
        cin>>arr[i];
        if(i%2==0 && arr[i] %2!=0){
            ans++;
        }
    }
    cout<<ans<<endl;
    return 0;
}
