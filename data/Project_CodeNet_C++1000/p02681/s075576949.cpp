#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    string s,t;
    cin >> s>>t;
    for(int i;i<s.size();i++){
        if(s.at(i)!=t.at(i)){
          cout<<"No"<<endl;
          return 0;
        }
    };
    
    cout<<"Yes"<<endl;
  
  return 0;
}
