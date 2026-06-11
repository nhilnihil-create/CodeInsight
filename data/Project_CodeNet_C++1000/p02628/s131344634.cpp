#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,k;
  cin >> n >> k;
  vector<int>kane(n);
  for(int i=0;i<n;i++)
    cin >> kane.at(i);
  sort(kane.begin(),kane.end());
  int su=0;
  for(int i=0;i<k;i++)
    su+=kane.at(i);
  cout << su << endl;
  return 0;
}