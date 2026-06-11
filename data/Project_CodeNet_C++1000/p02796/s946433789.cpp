#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<pair<int64_t,int64_t>>data(N);
  for(int i=0;i<N;i++){
    int64_t a;
    cin >> a;
    int64_t x;
    cin >> x;
    data.at(i).first=a+x;
    data.at(i).second=a-x;
  }
  sort(data.begin(),data.end());
  
  int ans=0;
  int64_t A=-1000000010;
  
  for(int i=0;i<N;i++){
    if(data.at(i).second>=A){
      ans++;
      A=data.at(i).first;
    }
  }
  
  cout << ans << endl;
  
}