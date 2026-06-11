#include <iostream>
using namespace std;
int main(){
	int i,j,n,k;
	cin>>n>>k;
	int a[n] = {0};
	int d;
	int x;
	for(i=0; i<k; i++){
		cin>>d;
		for(j=0; j<d; j++){
			cin>>x;
			a[x-1] = 1;
		}
	}
	int c = 0;
	for(i=0; i<n; i++){
		if(a[i] == 0){
			c++;
		}
	}
	cout << c ;
	return 0;
}