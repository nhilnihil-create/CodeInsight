#include <bits/stdc++.h>
#define rep(i,a,b) for(int i=a; i<b; i++)
#define lli long long
#define pb push_back
#define fast ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
using namespace std;
 
int main()
{
    fast
    int arr[5],temp;
    rep(i,0,5){
        cin>>arr[i];
        if(!arr[i])
        temp=i+1;
    }
    cout<<temp;
 
    return 0;
}