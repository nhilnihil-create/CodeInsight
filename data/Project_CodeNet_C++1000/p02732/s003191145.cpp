#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;


int main()
{
  ll n,a[200010],number[200010]={0};
  ll sum=0;
  cin>>n;
  rep(i,n){
    cin>>a[i];
    sum+=number[a[i]];
    number[a[i]]++;
  }


  rep(i,n)cout<<sum-(number[a[i]]-1)<<endl;
  return 0;
}
