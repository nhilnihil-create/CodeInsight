#include<iostream>
#include<string.h>
#include<string>
#include<cstdio>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#include<cmath>
#include<utility>
#include<set>
#define ll long long int
#define ld long double
#define INF 1000000000
#define EPS 0.0000000001
#define rep(i,n) for(i=0;i<n;i++)
using namespace std;
typedef pair<int, int> pii;

int main()
{
  int n;
  bool prime[247000]={};
  int i,j;

  for(i=2;i<sqrt(247000);i++){
    if(prime[i])continue;
    for(j=2;i*j<247000;j++)
	prime[i*j]=true;
  }

  while(true){
    cin>>n;
    if(n==0)break;
    if(n==1){
      cout<<"1"<<endl;
      continue;
    }
    int sum=0;
    for(i=n+1;i<=2*n;i++)
      if(prime[i]==false)sum++;
    cout<<sum<<endl;
  }
}