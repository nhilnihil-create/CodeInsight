#include<bits/stdc++.h>
#define ll long long
#define pb push_back
#define vl vector
using namespace std;
int main()
{
    ll t,i,n;
    ll a,b,c;
    ll arr[3];
    for(i=0;i<3;i++) cin>>arr[i];
    sort(arr,arr+3);
    if((arr[0]==arr[1] && arr[2]!=arr[1]) || (arr[1]==arr[2] && arr[0]!=arr[1])) cout<<"Yes";
    else cout<<"No";
    return 0;
}