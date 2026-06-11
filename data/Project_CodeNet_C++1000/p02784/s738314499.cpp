#include <iostream>

#define rep(i,n) for(int i = 0; i < n; i++)

using namespace std;

int main(){
	int h,n;
	cin >> h >> n;
	int a[n];
	long long sum = 0;
	rep(i,n) { cin >> a[i]; sum+=a[i]; }
	
	if(sum < h) cout << "No";
	else cout << "Yes";
	cout << endl;
	
	return 0;
}