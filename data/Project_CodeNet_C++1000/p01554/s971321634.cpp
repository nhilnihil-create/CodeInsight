
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
#include <functional>
#include <cassert>

using namespace std;


bool solve(){
	int n, m;
	cin>> n;
	vector<string> ID(n);
	for(int i=0;i<n;i++){
		string str;
		cin>> str;
		ID[i] = str;
	}
	cin>> m;	//ココ...
	int cnt = 0;
	for(int i=0;i<m;i++){
		string in;
		cin>> in;
		int status = 0;
		for(int j=0;j<n;j++){
			if(in == ID[j]){
				status++;
				break;
			}
		}
		if(!status){
			cout<< "Unknown ";
		}else{
			if(cnt%2){
				cout<< "Closed by ";
			}else{
				cout<< "Opened by ";
			}
			cnt++;
		}
		cout<< in<< endl;
	}
	
	return true;
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(10);
	solve();

	return 0;
}

 