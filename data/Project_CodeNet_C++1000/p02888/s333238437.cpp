#include <iostream>
#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main()
{
    int n;
    cin>>n;
    vector<int>l(n);
    for(int i=0;i<n;i++)cin>>l[i];
    sort(l.begin(),l.end());

    int cnt=0;
  for(int i=0;i<n-2;++i){
    int k=i+2;
    for(int j=i+1;j<n;++j){
        while(k<n&&l[i]+l[j]>l[k])++k;
        if(k>j)cnt+=k-j-1;
    }
  }
cout<<cnt;

    return 0;
}
