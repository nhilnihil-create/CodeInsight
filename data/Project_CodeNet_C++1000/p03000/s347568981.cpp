#include<iostream>
//#include <cmath>
//#include <bits/stdc++.h>

typedef long long ll;

using namespace std;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
  //  freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);
    int n,x;cin>>n>>x;int arr[n+1];arr[0]=0;
    for(int i=1;i<n+1;i++){
        int t;cin>>t;
        arr[i]=arr[i-1]+t;
    }int cnt=0;
    for(int i=0;i<n+1;i++){
        if(arr[i]<=x) {
            cnt++;
        }
        else{
            break;
        }
    }
    cout<<cnt<<"\n";
    return 0;
}
