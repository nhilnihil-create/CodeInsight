#include <bits/stdc++.h>
using namespace std;
#include <math.h>
#include <iomanip>
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const int INF=1001001001;
const int mod=1e9+7;

int main(){
  int N;
  cin>>N;
  vector<string>s(N);
  vector<int>t(N);
  for(int i=0;i<N;i++){
    cin>>s[i]>>t[i];
  }
  string x;
  cin>>x;
  int sum=0;
  for(int i=0;i<N;i++){
    if(s[i]==x){
      for(int j=i+1;j<N;j++){
        sum+=t[j];
      }
      cout<<sum<<endl;return 0;
    }
  }
  return 0;
}