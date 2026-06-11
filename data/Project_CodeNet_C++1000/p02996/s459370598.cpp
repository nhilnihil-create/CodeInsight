#include <bits/stdc++.h>
using namespace std;


int main() {

  int n;
  cin>>n;

  vector<pair<int, int> > pairs(n);
  for(int i=0;i<n;i++){
    int a,b;
    cin>>a>>b;
    pairs[i] = make_pair(b, a);
  }

  sort(pairs.begin(), pairs.end());

  int64_t sum=0;
  bool flg=true;
  for(int i=0;i<n;i++){
      sum+=pairs[i].second;
      if(sum> pairs[i].first){
          flg=false;
          break;
    }
  }

  if(flg)
    cout<<"Yes"<<endl;
  else
    cout<<"No"<<endl;

    return 0;
}