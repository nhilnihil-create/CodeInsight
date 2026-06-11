#include<iostream>
#include<algorithm>

using namespace std;

int main(){
	int MAX = 200000;
	
	int r[MAX],n;
	
	cin>>n;
	
	for(int i=0 ; i<n ; i++){
		cin>>r[i];
	} 

	int maxdiff = -1000000000;
	int minnum = r[0];
	
	for(int i=1 ; i<n ; i++){
		maxdiff = max(maxdiff, r[i]-minnum);
		minnum = min(minnum, r[i]); 
	} 
	
	cout<<maxdiff<<endl;

	return 0;
}