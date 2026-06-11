#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

#define REP(i,n) for(int i=0;i<(int)(n);i++)

using namespace std;

int main() {
  while(1){
    int n,m;
    cin>>n>>m;
    if(!n)break;
    vector<int> h(n);
    vector<int> w(m);
    REP(i,n)cin>>h[i];
    REP(i,m)cin>>w[i];
    vector<int> hs(n+1,0);
    vector<int> ws(m+1,0);
    partial_sum(begin(h),end(h),begin(hs)+1);
    partial_sum(begin(w),end(w),begin(ws)+1);
    vector<int> s1;
    vector<int> s2;
    REP(i,n+1){
      REP(j,i){
        s1.push_back(hs[i]-hs[j]);
      }
    }
    REP(i,m+1){
      REP(j,i){
        s2.push_back(ws[i]-ws[j]);
      }
    }
    sort(begin(s1),end(s1));
    int64_t sum = 0;
    for(int wd:s2){
      auto p=equal_range(begin(s1),end(s1),wd);
      sum += p.second - p.first;
    }
    cout<<sum<<endl;
  }
  return 0;
}