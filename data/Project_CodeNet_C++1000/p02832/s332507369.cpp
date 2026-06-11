#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(v) v.begin(),v.end()
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int INF=1e9;
const int di[] = {-1,0,1,0};
const int dj[] = {0,-1,0,1};

int main() {
  int n;
  cin>>n;
  vector<int> a(n);
  rep(i,n) cin>>a[i];
  int cnt=0;
  int key=1;
  rep(i,n){
    if(a[i]!=key){
      cnt++;
      continue;
    }
    if(a[i]==key){
      key++;
      continue;
    }
  }
  if(key==1){
    cout<<-1<<endl;
    return 0;
  }
  cout<<cnt<<endl;
}