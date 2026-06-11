#include<bits/stdc++.h>
using namespace std;

int main (void){
  string s;
  long long int a = 0,ans = 1;

  cin >> s;
  a = s.size();
  reverse(s.begin(),s.end());
  vector<long long int> q(a,0);

  q[0] = fmod((s[0] - '0'),2019);

  for(int i = 1;i < a;i++){
    ans = (ans * 10) % 2019;
    q[i] = fmod((s[i] - '0') * ans,2019);
    q[i] += q[i-1];
    q[i] = q[i] % 2019;
  }

  vector<int> l(2020,0);
  ans = 0;

  for(int i = 0;i < a;i++){
    l[q[i]]++;
  }
  l[0]++;

  for(int i = 0;i < 2019;i++){
    ans = ans + l[i] * (l[i] - 1) / 2;
  }



  cout << ans << endl;
  return 0;

}