#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<(n);i++)
using namespace std;

int h;
int A[10][5];

int Get(){
	int res=0;
	REP(i,h){
		for(int l=0;l<3;l++){
			if(A[i][l]==0) continue;
			int key=A[i][l],r=l;
			while(r<5 && A[i][r]==key) r++;
			if(r-l>=3){
				res+=key*(r-l);
				for(int j=l;j<r;j++) A[i][j]=0;
			}
		}
	}
	return res;
}
int Update(){
	REP(j,5){
		REP(i,h){
			if(A[i][j]) continue;
			for(int k=i+1;k<h;k++){
				if(A[k][j]){
					swap(A[i][j],A[k][j]);
					break;
				}
			}
		}
	}
}
int main() {

	while(cin>>h,h){
		for(int i=h-1;i>=0;i--) REP(j,5) cin>>A[i][j];
		int ans=0;
		while(true){
			int score=Get();
			if(score==0) break;
			ans+=score;
			Update();
		}
		cout<<ans<<endl;
	}	
	return 0;
}
