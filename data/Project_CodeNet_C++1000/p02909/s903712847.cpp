#include <bits/stdc++.h> 

using namespace std;
using ll=long long;
using ull=unsigned long long;
using pii=pair<int,int>;

#define INF LONG_MAX
#define MOD 1000000007
#define rng(a) a.begin(),a.end()
#define rrng(a) a.end(),a.begin()
#define endl "\n"

int main(){
  ios::sync_with_stdio(false);
  cin.tie(0);

  string S;
  cin>>S;
  vector<string>s={"Sunny","Cloudy","Rainy"};
  int c;
  for(int i=0;i<3;i++)if(s[i]==S)c=i;
  cout<<s[(c+1)%3]<<endl;
  return 0;
}
