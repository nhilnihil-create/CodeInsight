#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<queue>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<complex>
#define INF 2147483647
#define llINF 9223372036854775807
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long

using namespace std;
int main(){
  int n;
  while(cin>>n,n){
    ll ans=0;
    if(n==1)
      ans=1;
    else if(n==2)
      ans=1;
    else{
      for(int i=n+1;i<=2*n;i++){
	bool flag=true;
	for(int j=2;j<=sqrt(i);j++){
	  if(i%j==0){
	    flag=false;
	    break;
	  }
	}
	if(flag){
	  //cout<<i<<endl;
	  ans++;
	}
      }
    }
    cout<<ans<<endl;
  }
  return 0;
}