#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
vector <int> n;

int main(){
	map <int,int> a;
	int n,t;
	cin>>n;
	for(int i=1;i<n;i++){
		cin>>t;
		a[t]++;
	}
	for(int i=1;i<=n;i++){
		cout<<a[i]<<endl;
	}
	return 0;
}
