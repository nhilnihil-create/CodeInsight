#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define all(v) sort(v.begin(), v.end())
typedef long long ll;
using Graph = vector<vector<int>>;

int main(){
  int n;
  cin>>n;
  int cnt=0;
  rep(i,n){
    int a;
    int b;
    cin>>a>>b;
    if(a==b){
      cnt++;
    }else{
      cnt=0;
    }
    if(cnt==3){
      cout<<"Yes"<<endl;
      exit(0);
    }
  }
  cout<<"No"<<endl;
}
