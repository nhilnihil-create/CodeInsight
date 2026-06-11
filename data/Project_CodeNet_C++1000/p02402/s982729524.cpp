#include <iostream>
using namespace std;

string list[32];
int res=0;
int sa[1000];

int main(){
	long long int sum=0;
	int n;
	int a[10000];
	int max=0,min=10000;
	cin >> n;
	if(n>=1){
		cin >> a[0];
		max=min=sum=a[0];
	}
	for(int i=1;i<n;i++){
		cin >> a[i];
		if(max<a[i]) max=a[i];
		if(min>a[i]) min=a[i];
		sum+=a[i];
	}
	cout << min << " " << max << " " << sum << endl;
	return 0;
}