#include <bits/stdc++.h>
using namespace std;
 
int main(){
  int n;
  cin >> n;
  vector<pair<int,int>>time(n);
  for(int i=0;i<n;i++){
    int a,b;
    cin >> a >> b;
    time[i]=make_pair(b,a);
  }
  sort(time.begin(),time.end());
  long long ans=0;
  bool judge=true;
  for(int i=0;i<n;i++){
    ans+=time[i].second;
    if(ans>time[i].first){
      judge=false;
      break;
    }
  }
  if(judge){
    cout << "Yes" << endl;
  }
  else{
    cout << "No" << endl;
  }
}