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
  string s;
  cin>>N>>s;
  string t="RGB";
  vector<vector<int>>sum(N,vector<int>(100));
  for(int i=0;i<N;i++){
    sum[i][s[i]-'A']++;
    for(int j=0;j<3;j++){
      if(i+1<N){
        sum[i+1][t[j]-'A']+=sum[i][t[j]-'A'];
      }
    }
  }

  //cout<<sum[N-1]['R'-'A']<<endl;
  int64_t ans=0;
  for(int i=0;i<N;i++){
    char s1=s[i];
    for(int j=i+1;j<N;j++){
      if(s[j]!=s[i]){
        char s2=s[j];
        int len=j-i;
        char s3;
        for(int k=0;k<3;k++){
          if(t[k]!=s1&&t[k]!=s2){
            s3=t[k];
          }
        }
        //cout<<s3<<endl;
        ans+=sum[N-1][s3-'A']-sum[j][s3-'A'];
        if(j+len<N&&s[j+len]==s3){ans--;}
      }
    }
  }
  cout<<ans<<endl;
  return 0;
}