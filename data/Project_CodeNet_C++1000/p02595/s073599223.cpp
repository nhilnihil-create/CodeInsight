#include<bits/stdc++.h>
using namespace std;

double dist(int x, int y){
	double distance;
	distance = sqrt(pow(x, 2) + pow(y, 2));
	return distance;
}

int main(){
	int N, D;
	cin>>N>>D;
	int count = 0;
	int a[N][2];
	for(int i = 0; i<N; i++){
		cin>>a[i][0]>>a[i][1];
		if(dist(a[i][0], a[i][1])<= D){
			count++;
		}
	}
	cout<<count;
	return 0;
	
}