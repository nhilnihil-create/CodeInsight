#include <iostream>

using namespace std;
int n;
int dat[100][100];
int cost[100];
int done[100];

void prim(){
	for(int i=0;i<n;i++){
		cost[i]=1<<21;
		done[i]=0;
	}
	int s=0;	
	int next, ncost=1<<21;
	done[s]=1;
	cost[s]=0;
	while(1){
		ncost=1<<21;
		for(int j=0;j<n;j++){
			if(done[j]){
				for(int i=0;i<n;i++){
					if(dat[j][i]!=-1){
						if(cost[i]>=dat[j][i]&&!done[i]){
							cost[i]=dat[j][i];
						}
						if(ncost>cost[i]&&!done[i]){
							next=i;
							ncost=cost[i];
						}
					}
				}
			}
		}
//		cout<<"next:"<<next<<" cost:"<<cost[next]<<endl;
		done[next]=1;
		int flag=true;
		for(int i=0;i<n;i++){
			if(!done[i]) flag = false;
		}
		if(flag)
			return;
	}
}


int main(){
	cin>>n;
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>dat[i][j];
		}
	}
	prim();
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=cost[i];
	}
	cout<<sum<<endl;
	return 0;
}