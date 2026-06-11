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
	int n;
	cin>>n;
	int a[n],b[n];
	for(int i=0;i<n;i++){
		cin>>a[i];
		b[i] = a[i];
	}
	sort(a,a+n);
	int l=a[n-1];
	int sl = a[n-2];
	for(int i=0;i<n;i++){
		if(b[i]!=l){
			cout<<l<<endl;
		}
		else {
			cout<<sl<<endl;
		}
	}
	
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