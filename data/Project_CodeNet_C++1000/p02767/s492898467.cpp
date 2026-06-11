#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  vector<int>vec;
  float a, sum=0, avg=0, ans, res=0;
  for(int i=0; i<n; i++){
    cin >> a;
    vec.push_back(a);
    sum+=a;
  }
  avg=round(sum/n);
  for(int i=0; i<vec.size(); i++){
    ans=abs(avg-vec[i]);
    res+=ans*ans;
  }
  cout << res;
}
