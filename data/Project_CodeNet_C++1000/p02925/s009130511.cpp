#include <bits/stdc++.h>
//#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
#define rep(i,n) ;for(int i=0;i<n;++i)
int main() {
  int n;
  cin>>n;
  vector <vector<int>> a(n,vector<int> (n-1));
  for(int i=0;i<n;++i){
    for(int j=0;j<n-1;++j){
    cin>>a[i][j];
    a[i][j]--;
  }
  reverse(a[i].begin(),a[i].end());
}
vector <P> q;


auto check = [&](int i){
  if (a[i].size()==0) return;
  int j=a[i].back();
  if (a[j].size()==0) return;
  if (a[j].back()==i){
    P p(i,j);
    if (p.first>p.second)swap(p.first, p.second);
    q.push_back(p);
  }
};

rep(i,n){
  check(i);
}
int day=0;
while(!q.size()==0){
  day++;
  sort(q.begin(),q.end());
  q.erase(unique(q.begin(),q.end()),q.end());
  vector <P> pq;
  swap(q,pq);
  for (P pnow:pq){
    int i=pnow.first;
    int j=pnow.second;
    a[i].pop_back();
    a[j].pop_back();
  }
  for (P pnow:pq){
    int i=pnow.first;
    int j=pnow.second;
    check(i);check(j);
  }
}
for(int i=0;i<n;++i){
  if (a[i].size()>0)
  day=-1;
}
cout<<day;

}
