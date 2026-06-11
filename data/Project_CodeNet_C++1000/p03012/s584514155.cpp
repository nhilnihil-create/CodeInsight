#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define reps(i,n) for(int i=1;i<(int)(n);i++)

typedef long long ll;
using namespace std;
int main()
{
  int n;
  int w[110];
  cin>>n;
  rep(i,n)cin>>w[i];

  int csum[110];
  csum[0]=0;
  reps(i,n+1)csum[i]=csum[i-1]+w[i-1];
  // rep(i,n+1)cout<<csum[i]<<endl;
  int min=200;
  reps(i,n){
    if(abs((csum[n]-csum[i])-(csum[i]-csum[0]))<min)min=abs((csum[n]-csum[i])-(csum[i]-csum[0]));
  }

  cout<<min<<endl;
  return 0;
}
