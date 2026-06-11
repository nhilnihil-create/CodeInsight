#include <bits/stdc++.h>
#include <math.h>
#define ll long long
using namespace std;

int main() {
  int N,sum=0;
  bool f=false;
  cin>>N;
  string s[N],p;
  int t[N];
  for(int i=0;i<N;i++) cin>>s[i]>>t[i];
  cin>>p;
  for(int i=0;i<N;i++){
    if(s[i]==p){
      f=true;
      continue;
    }
    if(f) sum+=t[i];
  }
  cout<<sum<<endl;
}	
