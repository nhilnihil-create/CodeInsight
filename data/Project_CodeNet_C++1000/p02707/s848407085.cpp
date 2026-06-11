#include<bits/stdc++.h>
using namespace std;
int main()
{
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);  
    int n , m;
    cin>>n;
    int counter[n] = {0};
    vector <int> arr(n-1);
    for(int i = 0;i<n-1;i++)
    {
        cin>>arr[i];
        counter[arr[i]-1]++;
    }
    for(int i = 0;i<n;i++)
    {
        
        cout<<counter[i]<<endl;
    }
    return 0;
}