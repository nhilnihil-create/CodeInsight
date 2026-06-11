#include <bits/stdc++.h>
using namespace std;

int main(){
  int h,w,m;
  cin>>h>>w>>m;
  vector<set<int>> b(h);
  vector<int> sums_h(h,0);
  vector<int> sums_w(w,0);
  int bh,bw;
  for(int i=0;i<m;i++){
    cin>>bh>>bw;
    sums_h.at(bh-1)++;
    sums_w.at(bw-1)++;
    b.at(bh-1).insert(bw-1);
  }
  int result=0;
  int max_h=0;
  int max_w=0;
  vector<int> index_h;
  vector<int> index_w;
  for(int i=0;i<h;i++){
    if(max_h<sums_h.at(i)){
      max_h=sums_h.at(i);
      index_h.clear();
      index_h.push_back(i);
    }else if(max_h==sums_h.at(i)){
      index_h.push_back(i);
    }
  }
  for(int j=0;j<w;j++){
    if(max_w<sums_w.at(j)){
      max_w=sums_w.at(j);
      index_w.clear();
      index_w.push_back(j);
    }else if(max_w==sums_w.at(j)){
      index_w.push_back(j);
    }
  }
  for(int i=0;i<index_h.size();i++){
    for(int j=0;j<index_w.size();j++){
      if(!b.at(index_h.at(i)).count(index_w.at(j))){
        cout<<max_h+max_w<<endl;
        return 0;
      }
    }
  }
  cout<<max_h+max_w-1<<endl;
}
 