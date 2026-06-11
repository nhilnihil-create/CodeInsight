#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  ll N,count=0;
  cin>>N;
  vector<string> s(N);
  for(int i=0; i<N; i++){
    cin>>s[i];
    sort(s[i].begin(),s[i].end());
  }
  sort(s.begin(),s.end());
  ll huga=0;
  for(int i=0; i<N-1; i++){
    if(s[i]==s[i+1]){
      count=count+huga+1;
      huga++;
    }
    else{
      huga=0;
    }
  }
  cout<<count<<endl;
}
  