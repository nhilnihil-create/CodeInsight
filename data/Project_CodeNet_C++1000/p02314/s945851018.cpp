#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main(){
	int n,m;
	cin >> n >> m;
	vector<int> C(m);
	vector<int> T(n+1,INT_MAX);
	for (int i=0;i<m;i++){
		cin >> C[i] ;
	}
	
	T[0]=0;
	T[1]=1;
	for (int i=2;i<=n;i++){
		for(int j=0;j<m;j++){
			if(i-C[j]>=0 && T[i]>T[i-C[j]]+1){
				T[i]=T[i-C[j]]+1;
			}
		}
	}
	cout << T[n] << endl;
	return 0;
}