#include<bits/stdc++.h>
using namespace std;
int main(){
	int n,k,q;cin>>n>>k>>q;
  	vector<int >points(n,0);
  for(int i=0,a;i<q;i++){
  	cin>>a;
    points[a-1]+=1;
  }
  for(int i=0;i<n;i++){
  	if((k-(q-points[i]))>0)cout<<"Yes\n";
    else cout<<"No\n";
  }
}