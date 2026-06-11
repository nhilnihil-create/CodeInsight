#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int n;
vector<pair<int,int>> tasks;
int main() {
  cin >> n;
  for(int i =0;i<n;i++){
    int a,b;
    cin >> a >> b;
    tasks.emplace_back(b,a);
  }
  sort(tasks.begin(),tasks.end());
  int comp = 0;
  bool hantei = true;
  for(auto v : tasks){
    comp += v.second;
    if(comp > v.first){
      hantei = false;
      break;
    }
  }
  cout << (hantei? "Yes":"No") << endl;
  return 0;
}
