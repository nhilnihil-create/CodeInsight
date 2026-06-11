#include<bits/stdc++.h>
#define IOS ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int A=1000005;
int main(){IOS;
	int n;
	cin>>n;
	vector<int>a(n);
	vector<int>b(1000005,0);
	bool pairwise=true;
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[a[i]]++;}
		for(int i=2;i<A;i++){
			int cnt=0;
			for(int j=i;j<A;j+=i){
				  cnt+=b[j];}
				  if(cnt>1)
				  pairwise=false;}
				  bool setwise=true;
				  int g=0;
				  for(int i=0;i<n;i++){
					   g=__gcd(a[i],g);}
					  if(g!=1)
					  setwise=false;
					  if(pairwise)
					  cout<<"pairwise coprime"<<endl;
					  else if(setwise)
					  cout<<"setwise coprime"<<endl;
					  else cout<<"not coprime"<<endl;}
					  