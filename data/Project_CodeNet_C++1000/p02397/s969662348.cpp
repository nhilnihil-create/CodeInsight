#include <iostream>
#include <vector>

using namespace std;

int main(){
	vector<int> x;
	int i;
	while(1){
		int a,b;
		cin>>a>>b;
		if (a==0 && b==0){
			break;
		}
		x.push_back(a);
		x.push_back(b);
	}
	for (vector<int>::size_type i=0;i<x.size();i+=2){
		if (x[i]>x[i+1]){
			cout<<x[i+1]<<" "<<x[i]<<endl;
		}
		else{
			cout<<x[i]<<" "<<x[i+1]<<endl;
		}
	}
	return 0;
}