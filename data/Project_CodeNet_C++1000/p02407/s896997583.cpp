#include <iostream>
using namespace std;

int main(){
	int n,i,a[100];
	cin >> n;
	i=n;
	while(i--) cin >> a[i];
	for(i=0;i<n;i++){
		cout << a[i];
		if(i!=n-1) cout << " ";
	}
	cout << endl;
	return 0;
}