#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
queue<int>q[1003];
int b[1003];//b[i]表明时间  每天一次
int main(){
	int n;
	cin>>n;
	
	for(int i=1,tmp;i<=n;i++){
		for(int j=1;j<n;j++){
	   cin>>tmp;
	   q[i].push(tmp);
  }
}
  int flag=0;
	while(1){
		flag=0;
		for(int i=1;i<=n;i++){
			if(q[i].empty()) continue;//一有两个都有
			if(q[q[i].front()].front()==i){
				b[i]=b[q[i].front()]=max(b[i],b[q[i].front()])+1;
		  	q[q[i].front()].pop();
			  q[i].pop();
		  	flag=1;
		  }
		}
		int sum=0;
		for(int i=1;i<=n;i++){
			sum+=q[i].size();
		}
		if(!sum) break;
		if(!flag) break;
	}
	if(!flag) cout<<-1<<'\n';
	else{
		int ans=0;
		for(int i=1;i<=n;i++) ans=max(ans,b[i]);
		cout<<ans;
	}
}