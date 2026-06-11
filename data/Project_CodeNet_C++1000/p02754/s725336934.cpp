#include<iostream>
#include<stdio.h>
using namespace std;
using ll=long long;
#include<algorithm>
#include<set>
#include<vector>
#define rep(i,n) for(int i=0;i<(n);i++)
using P=pair<int,int>;
const int mod=1000000007;


int main(){
ll n,a,b;
cin>>n>>a>>b;
ll c=a+b;
ll ans=(n/c)*a;
ans+=min(n%c,a);
cout<<ans<<endl;
return 0;
}