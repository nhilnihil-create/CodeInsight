#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;
typedef long long ll;

vector<pair<char,int> > rfe_tuple(string S){
  vector<pair<char,int> > ff;
  int sum=1;
  for (int i=1;i<S.length();i++){
    while(S[i]==S[i-1]){
      sum++;
      i++;
    }
    ff.push_back(make_pair(S[i-1],sum));
    sum=1;
  }
  if(S[S.length()-1]!=S[S.length()-2]) ff.push_back(make_pair(S[S.length()-1],1));
  return ff;
}

int main(){
  string S;
  cin >> S;
  int len = S.length();
  vector<pair<char,int> > f;
  f=rfe_tuple(S);
  int sum=0;
  int ans[len];
  for(int i=0;i<len;i++){
    ans[i]=0;
  }
  for(int i=0;i<f.size();i++){
    if(f[i].first=='R'){
      sum += f[i].second;
      if((f[i].second+f[i+1].second)%2==0){
	ans[sum-1]=(f[i].second+f[i+1].second)/2;
	ans[sum]=(f[i].second+f[i+1].second)/2;
      }
      else if(f[i].second%2==0) {
	ans[sum-1]=(f[i].second+f[i+1].second)/2;
	ans[sum]=(f[i].second+f[i+1].second)/2+1;
      }
      else{
	ans[sum-1]=(f[i].second+f[i+1].second)/2+1;
	ans[sum]=(f[i].second+f[i+1].second)/2;
      }
    }
    sum += f[i+1].second;
    i++;
  }
  for(int i=0;i<len;i++){
    cout << ans[i] << " ";
  }
}
