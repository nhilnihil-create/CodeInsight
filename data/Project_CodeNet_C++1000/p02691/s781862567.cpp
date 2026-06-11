#include<bits/stdc++.h>
using namespace std;
int main(){
	int n;
	int a[200005]={0};
	int b[200005]={0};
	cin>>n;
	for(int i=1; i<=n; i++) cin>>a[i];
	for(int i=1; i<=n; i++){
		b[i] = i-a[i];
		a[i]+=i;
	}
	long long ret = 0;
	map<int,int>m;
	map<int,int>::iterator it;
	for(int i=1; i<=n; i++){
		it = m.find(b[i]);
		if(it!=m.end()) ret+=it->second;
		
		it = m.find(a[i]);
		if(it!=m.end()) it->second+=1;
		else m.insert(make_pair(a[i],1));
	}
	cout<<ret;
}