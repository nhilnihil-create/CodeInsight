#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    int n , m;
    cin>>n>>m;
    int arr[m];
    int sum = 0;
    for(int i = 0;i<m;i++)
    {
        cin>>arr[i];
        sum = sum + arr[i];
    }
    if(sum>n)
    cout<<"-1";
    else{
        cout<<n - sum;
    }
    return 0;
}