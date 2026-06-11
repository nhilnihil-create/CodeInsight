#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    int n,sum=0;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) cin>>a[i],sum^=a[i];
    for(int i=0;i<n;i++) cout<<(sum^a[i])<<" ";
  	return 0;
}
