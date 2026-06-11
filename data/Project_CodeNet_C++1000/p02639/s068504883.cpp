#include <bits/stdc++.h>
#define REP(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    vector<int> vt(5);
    REP(i,5) {
        cin >>vt.at(i);
        if(vt.at(i)==0){
        cout<<i+1<<endl;
        }
    }
  
  return 0;
}
