#include<iostream>
#include<vector>
using namespace std;

int main(){
	int n;
	cin>>n;

	vector<int> d(n);

	for(int i=0;i<n;i++){
		cin>>d.at(i);
	}

	int total=0;

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			total += d.at(i)*d.at(j);
		}
	}

	cout<<total<<endl;

	return 0;
}