#include<bits/stdc++.h>
using namespace std;
int h,w,k;
int arr[6][6];
int temp[6][6];
void copy(){
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++) temp[i][j] = arr[i][j];
	}
}
int solve(){
	int ret = 0;
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			if(temp[i][j]==1) ret++;
		}
	}
	return ret; 
}
void paint(int row_state,int col_state){
	for(int i=0; i<h; i++){
		if((1<<i)&row_state){
			for(int j=0; j<w; j++) temp[i][j] = 2;
		}
	}
	for(int i=0; i<w; i++){
		if((1<<i)&col_state){
			for(int j=0; j<h; j++) temp[j][i] = 2;
		}
	}
}
int main(){
	cin>>h>>w>>k;
	for(int i=0; i<h; i++){
		string s;
		cin>>s;
		for(int j=0; s[j]; j++){
			if(s[j]=='#') arr[i][j] = 1;
		}
	}
	int ret = 0;
	for(int i=0; i<(1<<h); i++){
		for(int j=0; j<(1<<w); j++){
			copy();
			paint(i,j);
			if(solve()==k) ret++;
		}
	}
	cout<<ret;
}