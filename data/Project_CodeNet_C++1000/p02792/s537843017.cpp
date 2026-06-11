#include <bits/stdc++.h>
using namespace std;


int main() {
  int N;
  cin>>N;
  vector<vector<long>> a(10,vector<long>(10));
  for(int i=1;i<=N;i++){
    int t=i;
    int b=i%10;
    while(t>9) t/=10;
    a[t][b]++;
  }
  long ans=0;
  for(int i=1;i<=9;i++) for(int j=1;j<=9;j++) ans+=a[i][j]*a[j][i];
cout<<ans<<endl;
}
