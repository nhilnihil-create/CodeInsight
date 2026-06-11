#include<bits/stdc++.h>
using namespace std;
int main(){
  int64_t n,m,count=0,cnt=0;
  cin >> n >> m;
  int64_t a[m],sum[n],c[n];
  vector<string> b(m);
  for(int64_t i=0;i<n;i++){
    sum[i]=0;
    c[i]=0;
  }
  for(int64_t i=0;i<m;i++){
    cin >> a[i] >> b[i];
  }
  for(int64_t i=0;i<m;i++){
    if(b[i]=="WA")c[a[i]-1]++;
    if(sum[a[i]-1]==0 && b[i]=="AC"){
      sum[a[i]-1]=1;
      count++;
      cnt+=c[a[i]-1];
    }
  }
  cout << count << " " << cnt << endl;
}
    
      