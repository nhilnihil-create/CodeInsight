#include<bits/stdc++.h>
using namespace std;
int arr[3][3];
bool bingo[3][3];

int main(){
	for(int i=0; i<3; i++){
		for(int j=0; j<3; j++) cin>>arr[i][j];
	}
	int n;
	cin>>n;
	while(n--){
		int a;
		cin>>a;
		for(int i=0; i<3; i++){
			for(int j=0; j<3; j++){
				if(arr[i][j]==a) bingo[i][j] = true;
			}
		}
	}
	
	bool bing = false;
	for(int i=0; i<3; i++){
		int ret = 0;
		int ret2 = 0;
		for(int j=0; j<3; j++){
			ret+=bingo[i][j];
			ret2+=bingo[j][i];
		}
		if(ret==3) bing = true;
		if(ret2==3) bing = true;
	}
	if((bingo[0][0]+bingo[1][1]+bingo[2][2])==3) bing = true;
	if((bingo[2][0]+bingo[1][1]+bingo[0][2])==3) bing = true;
	if(bing) cout<<"Yes";
	else cout<<"No";
}