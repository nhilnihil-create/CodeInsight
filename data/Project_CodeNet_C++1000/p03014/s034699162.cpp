#include<bits/stdc++.h>
using namespace std;
int h,w;
int Left[2005][2005];
int Right[2005][2005];
int Up[2005][2005];
int Down[2005][2005];
int arr[2005][2005];

int main(){
	cin>>h>>w;
	for(int i=1; i<=h; i++){
		string s;
		cin>>s;
		for(int j=0; s[j]; j++){
			if(s[j]=='#') arr[i][j+1] = 1;
		}
	}
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++){
			if(arr[i][j]) Right[i][j] = 0;
			else Right[i][j] = Right[i][j-1]+1;
		}
	}
	for(int i=1; i<=h; i++){
		for(int j=w; j>=1; j--){
			if(arr[i][j]) Left[i][j] = 0;
			else Left[i][j] = Left[i][j+1]+1;
		}
	}
	for(int i=1; i<=w; i++){
		for(int j=1; j<=h; j++){
			if(arr[j][i]) Down[j][i] = 0;
			else Down[j][i] = Down[j-1][i]+1;
		}
	}
	for(int i=1; i<=w; i++){
		for(int j=h; j>=1; j--){
			if(arr[j][i]) Up[j][i] = 0;
			else Up[j][i] = Up[j+1][i]+1;
		}
	}
	int maxlight = 0;
	for(int i=1; i<=h; i++){
		for(int j=1; j<=w; j++){
			if(arr[i][j]) continue;
			int light = Left[i][j]+Right[i][j]+Up[i][j]+Down[i][j]-4;
			maxlight = max(maxlight,light+1);
		}
	}
	cout<<maxlight;
}