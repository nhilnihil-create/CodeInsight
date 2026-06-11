#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin >> a.at(i);
	}
	for(int i=0;i<n;i++){
		if(i==0){
			a[i]--;
			continue;
		}
		if(i==n-1) break;
		if(a[i]>a[i-1]) a[i]--;
	}
	bool flag = true;
	for(int i=1;i<n;i++){
		if(a[i]<a[i-1]) flag = false;
	}
	if(flag){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
}
