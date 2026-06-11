#include<bits/stdc++.h>
using namespace std;int k,i=2;main() {cin>>k;cout<<k<<":";while (i<=sqrt(k)){if(k%i == 0){cout<<' '<<i;k/=i;}else{i++;}}if(k-1){cout<<' '<<k;}cout<<endl;}