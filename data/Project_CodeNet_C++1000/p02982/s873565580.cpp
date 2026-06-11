// Created by ...Lusifer
#include<bits/stdc++.h>
using namespace std;
 
#define pb 		push_back
#define mp 		make_pair
#define prior   priority_queue
#define MOD 	1000000007
#define INF64 	(long long)1e18
#define INF 	(int)1e9
#define PI 		3.1415926535897932384626433832795 
#define ll      long long
#define ld		long double
#define ret     return
#define NUM 	1000001
const int SIZE = 2e5+4;
void fastio(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void solveTest(){
	int n,d;
	cin>>n>>d;
	int a[n][d];
	for(int i=0;i<n;i++){
		for(int j=0;j<d;j++){
			cin>>a[i][j];
		}
	}
	int cnt=0;
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			ll sum=0;
			for(int k=0;k<d;k++){
				sum += abs(a[i][k]-a[j][k])*abs(a[i][k]-a[j][k]);
			}
			int x = sqrt(sum);
			if(sqrt(sum)==x){
				cnt++;
			}
		}
	}
	cout<<cnt<<endl;
	
	return ;
}
 
int main(){
	fastio();

	int t=1;
	//cin>>t;
	while(t--){
		solveTest();
 
	}
	return 0;
}