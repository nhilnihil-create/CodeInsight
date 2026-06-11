#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
  cin>>n;
  vector<int >perm(n,0);
  for(int i=0;i<n;i++){
  	cin>>perm[i];
  }
  int tot=0;
  int fsd = 1;
  for(int i=0;i<n;i++){
  	if(perm[i]==fsd){fsd+=1;tot++;}
  }
  if(tot==0)cout<<-1;
  else cout<<n-tot;
}