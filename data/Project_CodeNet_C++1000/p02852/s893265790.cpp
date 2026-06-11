#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
  int n,m; cin >> n >> m;
  int c=0,p=0;
  string s; cin >> s;
  reverse(s.begin(), s.end());
  vector<int> v;
  for(int i=0;i<n+1;i++){
  	if(p==n) break;
    bool f = false;
    for(int j=min(n,p+m); j>p; j--){
    	if(s[j]=='0'){f = true;v.push_back(j-p); p = j;  break;}
    }
    if(f) c++;
    else{
      cout << "-1" << endl;
      return 0;
    }
  }
  reverse(v.begin(), v.end());
  for(auto x: v) cout << x << " ";
  cout << endl;
  return 0;
}