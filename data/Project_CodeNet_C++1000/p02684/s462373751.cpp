#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
using namespace std;
int main(){
int n;
long long k;
  cin>>n>>k;
  vector<int>a(n);
  rep(i,n)cin>>a.at(i);
  
  vector<int>s;
  vector<int>ord(n+1,-1);
  int c=1,l=0;
  {
  	int v=1;
    while(ord.at(v) == -1){
      	ord.at(v)=s.size();
      	s.push_back(v);
    	v=a.at(v-1);
    }
    c=s.size()-ord.at(v);
    l=ord.at(v);
  }
  
  if(k<l) cout<<s.at(k)<<endl;
  else{
  	k-=l;
    k%=c;
    cout<<s.at(l+k)<<endl;
  }
}