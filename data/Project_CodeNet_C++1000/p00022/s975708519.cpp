#include<bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  while(n!=0){
    vector<int> a(n);
    for(int i=0;i<n;i++) cin >> a.at(i);

    vector<int> s(n+1);
    s.at(0) = 0;
    for(int i=1;i<n+1;i++) s.at(i) = s.at(i-1)+a.at(i-1);

    int ans= -1000000000;
    for(int i=1;i<n+1;i++){
      for(int j=0;j<i;j++){
        ans = max(s.at(i)-s.at(j),ans);
      }
    }

    cout << ans << endl;

    cin >> n;
  }
}


