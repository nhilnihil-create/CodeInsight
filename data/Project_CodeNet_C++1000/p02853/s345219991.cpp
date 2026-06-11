#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll arr[1010];
int main()
{
    //freopen("in.txt", "r", stdin);
    arr[1]=300000;
    arr[2]=200000;
    arr[3]=100000;
    ll x,y;
    cin>>x>>y;
    if(x==1 && y==1){
        cout<<arr[x]+arr[y]+400000<<endl;
    }
    else{
        cout<<arr[x]+arr[y]<<endl;
    }

}

