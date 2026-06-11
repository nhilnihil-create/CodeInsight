#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,a;    
    int ans[200005]={};
    vector<int> vec;

    cin>>n;
    for(int i=0;i<n-1;i++){
        cin>>a;
        ans[a-1]++;
    }
    for(int i=0;i<n;i++) cout<<ans[i]<<endl;

    return 0;

}