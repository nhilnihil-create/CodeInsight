
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <stack>
#include <cctype>
#include <complex>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
#include <cassert>

using namespace std;


bool solve(){
	vector<vector<int> > a(100, vector<int>(2, 0));
	for(int i=0;i<100;i++){
		a[i][0] = i;
	}
	int n;
	while(cin>>n){
		a[n-1][1]++;
	}
	for(int i=0;i<100-1;i++){
		for(int j=i;j<100;j++){
			if(a[i][1] < a[j][1]){
				swap(a[i][0],a[j][0]);
				swap(a[i][1],a[j][1]);
			}
		}
	}
	int hoge=0;
	while(1){
		cout<< a[hoge][0]+1<< endl;
		if(a[hoge][1]!=a[hoge+1][1] || hoge==99) break;
		hoge++;
	}
	
	return true;
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(10);
	solve();

	return 0;
}

 