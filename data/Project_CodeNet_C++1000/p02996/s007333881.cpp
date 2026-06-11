#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin>>n;
    vector<pair<int,int> >arr(n);
    for(int i=0; i<n; i++){
        cin>>arr[i].second>>arr[i].first;
    }
    sort(arr.begin(),arr.end());
    int s=0;
    int flag=0;
    for(int i=0; i<n; i++){
        if(s+arr[i].second>arr[i].first){
            flag=1;
            break;
        }
        else{
            s+=arr[i].second;
        }
    }
    if(flag)
         cout<<"No";
    else
        cout<<"Yes";
return 0;
}