#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	int n,q,k;
	cin>>n>>k>>q;
	int p[n]={};
	int s=q-k;
	for(int i=0; i < q; i++){
		int b;
		cin>>b;
		b--;
		p[b]++;
	}
	for(int i=0; i < n; i++){
		if(p[i]>s){
			cout<<"Yes"<<endl;
		}else{
			cout<<"No"<<endl;
		}
	}
}