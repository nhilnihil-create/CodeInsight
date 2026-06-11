#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> vec;
	for (int i=0; i<n; i++){
		int x;
		cin>>x;
		vec.push_back(x);
	}
	int suma=0;
	for (int i=1; i<n-1; i++){
		if ((vec[i-1]>vec[i]&&vec[i]>vec[i+1])||(vec[i-1]<vec[i]&&vec[i]<vec[i+1]))
			suma++;
	}
	cout<<suma;
}