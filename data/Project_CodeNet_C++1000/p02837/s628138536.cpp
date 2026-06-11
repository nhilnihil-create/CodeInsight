#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
//0　謎　１本と　
int n;


int main(){
	cin>>n;
	int  t[n][n]={};
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			t[i][j]= -1;
		}
	}
	int k=(1<<n)-1;
	//cout<<k<<endl;
	//cout<<"K="<<k<<endl;

	for(int i=0; i<n; i++){
		int a;
		cin>>a;
		for(int j=0; j<a; j++){
			int x,y;
			cin>>x>>y;
			x--;
			t[i][x]=y;
		}
	}
	//for(int i=0; i<n; i++){
	//	for(int j=0; j<n; j++){
	//		cout<<t[i][j]<<" ";
	//	}
	//	cout<<endl;
	//}
	//cout<<"a"<<endl;
	int ans=0;
	for(int i=0; i<=k; i++){//調子乗ってビットdpしたら怒られた
		int d[n]={};
		
		for(int j=0; j<n; j++){
			if(i>>j & 1){
				d[j] = 1;
			}
		}
		bool ok = true;
		for(int j=0; j<n; j++){
			if(d[j]==1){
				for(int q=0; q<n; q++){
					if(t[j][q] == -1) continue;
					if(t[j][q] != d[q]){
						ok = false;
					}
				}
			}
		}
					
		if(ok) ans=max(__builtin_popcount(i),ans);
	}

	
	cout<<ans<<endl;
}