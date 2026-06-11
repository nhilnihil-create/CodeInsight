#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
  int N;
  cin>>N;
  int w[N],a[N];
  for(int i=0;i<N;++i) cin>>w[i];
  for(int i=0;i<N;++i) {
    int ans1=0;
    int ans2=0;
    int ans=0;
    for(int j=0;j<=i;++j) {
      ans1+=w[j];
    }
    for(int k=i+1;k<N;++k) {
      ans2+=w[k];
    }
    ans=ans1-ans2;
    if(ans<0) ans*=(-1);
    a[i]=ans;
  }
  sort(a,a+N);
  cout<<a[0];
}
