#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;cin>>n;
	vector<int> vc;
	int total= 0;
	for(int i=0;i<n;i++){
	    int item;cin >> item;
	    vc.push_back(item);
	}
	for(int i=0;i<n;i++){
	   for(int j=0;j<i;j++){
	       total+=vc[i]*vc[j];
	   }
	}
	cout << total;
}