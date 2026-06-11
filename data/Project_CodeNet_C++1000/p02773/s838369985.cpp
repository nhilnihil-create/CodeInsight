#include <bits/stdc++.h>
using namespace std;

int main(){
  int n;
  cin >> n;
  map<string,int> M;
  vector<string> s(n);
  vector<string> v;
  int mx = 0;
  for(int i = 0; i < n; i++)
  {
    cin >> s.at(i);
    M[s.at(i)]++;
    mx = max(mx,M[s.at(i)]);
  }
  for(int i = 0; i < n; i++)
  {
    if(M[s.at(i)]==mx)
    {
      v.push_back(s.at(i));
      M[s.at(i)] = -1;
    }
  }
  sort(v.begin(), v.end());
  for(int i = 0; i < v.size(); i++)
  {
    cout << v.at(i) << endl;
  }
  return 0;

}