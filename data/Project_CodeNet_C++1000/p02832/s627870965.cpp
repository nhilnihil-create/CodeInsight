#include<bits/stdc++.h>
using namespace std;
int main(){
	int t,n,a=1,arr[200000],j=0;
	queue <int> q;
	cin>>t;
	for(int i=1;i<=t;i++){
		cin>>n;
		q.push(n);
	}
	for(int i=1;i<=t;i++){
		if(q.front()==a){
			arr[a-1]=q.front();
			q.pop();
			a++;
		}
		else {
			q.pop();
			j++;
		}
	}
	if(a==1) cout<<"-1"<<endl;
	else cout<<j<<endl;
}
