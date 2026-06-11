#include<bits/stdc++.h>
using namespace std;
int main(){
  int n,k;cin >> n >> k;
  vector<int> a(n);
  int sum=0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    sum+=a[i];
  }
  vector<int> v;
  for(int i=1;i*i<=sum;i++){
    if(sum%i==0){
      v.push_back(i);
      if(i*i!=sum){
        v.push_back(sum/i);
      }
    }
  }
  sort(v.begin(),v.end(),greater<int>());
  for(int i=0;i<v.size();i++){
    vector<int> r(n),sl(n),sr(n);
    for(int j=0;j<n;j++){
      r[j]=a[j]%v[i];
    }
    sort(r.begin(),r.end());
    for(int j=0;j<n;j++){
      if(!j){
        sl[j]=r[j];
      }
      else{
        sl[j]=sl[j-1]+r[j];
      }
    }
    for(int j=n-1;j>=0;j--){
      if(j==n-1){
        sr[j]=(v[i]-r[j])%v[i];
      }
      else{
        sr[j]=sr[j+1]+(v[i]-r[j])%v[i];
      }
    }
    int cnt=1e9+5;
    for(int j=0;j<n-1;j++){
      if(sl[j]==sr[j+1]){
        cnt=min(cnt,sl[j]);
      }
    }
    if(cnt<=k){
      cout << v[i] << endl;
      return 0;
    }
  }
}