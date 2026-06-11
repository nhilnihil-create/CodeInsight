#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF=1LL<<60;
const int inf=1<<30;
const int mod=1e9+7;
vector<int> Zalgo(string s){
  int m=s.size();
  vector<int> res(m);
  res[0]=m;
  int i=1,j=0;
  while(i<m){
    while(i+j<m&&s[j]==s[j+i]){
      j++;
    }
    res[i]=j;
    if(j==0){
      i++;
      continue;
    }
    int k=1;
    while(i+k<m&&k+res[k]<j){
      res[i+k]=res[k];
      k++;
    }
    i+=k,j-=k;
  }
  return res;
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;cin >> n;
    string s;cin >> s;
    int ans=0;
    for(int i=0;i<n;i++){
        vector<int> lcp=Zalgo(s.substr(i,n-i));
        for(int j=0;j<n-i;j++){
            chmax(ans,min(lcp[j],j));
        }
    }
    cout << ans << endl;
}