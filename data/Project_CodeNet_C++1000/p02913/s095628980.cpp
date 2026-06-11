





#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
#define rep(i,n) for(int i=0;i<n;++i)


//vector<vector<int>> z(n,vector<int>(2));
//n番目から数えてm個の文字列をXに置換したい場合はreplace(n,m,X) teWttest
//s1.substr(3,3);
//n番目以降の文字列をm個取り出す、上だとtte

int main(){
  int n;
  cin>>n;
  string s;
  cin>>s;

  vector<vector<int>> d(n+1,vector<int> (n+1,0));
  for(int i=n-1;i>=0;i--){
    for (int j=n-1;j>=0;j--){
      if (i==j)continue;
      if (s[i]==s[j]){
        d[i][j]=max(d[i][j],d[i+1][j+1]+1);
      //  cout<<d[i][j]<<endl;
      }
    }
  }
  int ans=0;
  for(int i=n-1;i>=0;i--){
    for (int j=i-1;j>=0;j--){
      ans=max(ans,min(d[i][j],i-j));

    }
  }
  cout<<ans;
  }
