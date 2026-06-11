#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin >> n;
  vector<int> a(n);
  int cnt=0;
  for(int i=0;i<n;i++){
    cin >> a[i];
    if(a[i]<0){
      cnt++;
    }
  }
  cnt=max(cnt,1);
  cnt=min(cnt,n-1);
  sort(a.begin(),a.end());
  vector<pair<int,int>> c(n-1);
  for(int i=cnt;i<n-1;i++){
    c[i-cnt]=make_pair(a[0],a[i]);
    a[0]-=a[i];
  }
  for(int i=0;i<cnt;i++){
    c[n-cnt-1+i]=make_pair(a[n-1],a[i]);
    a[n-1]-=a[i];
  }
  cout << a[n-1] << endl;
  for(int i=0;i<n-1;i++){
    cout << c[i].first << " " << c[i].second << endl;
  }
}