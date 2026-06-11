#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
typedef long long ll;

int main() {
	int n;
  	cin>>n;
  
	vector<int> p(n);
  	vector<int> q(n);
  
  int cp=0;
  int cq=0;
  
  rep(i,n)cin>>p[i];
  rep(i,n)cin>>q[i];
  
  while(prev_permutation(p.begin(),p.end())){
  	cp++;
  }
  
  while(prev_permutation(q.begin(),q.end())){
  	cq++;
  }

  cout<<abs(cp-cq)<<endl;
  
}