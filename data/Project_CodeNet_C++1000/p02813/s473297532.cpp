#include<bits/stdc++.h>
using namespace std;
#define int long long int

int solve(int n,int arr[]){
    int temp[n];
    for(int i=1;i<=n;i++){
        temp[i-1]=i;
    }
    int idx=0;
    do{   
        int flag=0;
        for(int i=0;i<n;i++){
            if(arr[i]!=temp[i]){
                flag=1;
                break;
            }
        }
        if(!flag){
            return idx;
        }
        idx++;
    }
    while(next_permutation(temp,temp+n));
}
int32_t main()
{
    int n;cin>>n;

    int arr1[n],arr2[n];

    for(int i=0;i<n;i++) cin>>arr1[i];
    for(int i=0;i<n;i++) cin>>arr2[i];

    int num1=solve(n,arr1);
    int num2=solve(n,arr2);

    cout<<abs(num1-num2)<<endl;

    return 0;
}