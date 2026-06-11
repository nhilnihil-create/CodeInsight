
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
	vector<int> a(1);
	int n;
	cin>> a[0]>> n;
	if(a[0]==0 && n==0) return false;
	
	int ans1 = 0 , ans2 = 0, ans3 = 0;
	while(ans3 == 0){
		int a_crr = a[a.size()-1];
		vector<int> b;
		for(int i=0;i<n;i++){
			b.push_back(a_crr % 10);
			a_crr /= 10;
		}
		sort(b.begin(), b.end());
		int l=0, h=0;
		int k = 1;
		for(int i=0;i<n;i++){
			h += b[i] * k;
			l += b[n-1-i] * k;
			k *= 10;
		}
		int a_nex = h - l;
		for(int i=0;i<a.size();i++){
			if(a[i] == a_nex){
				ans1 = i;
				ans2 = a_nex;
				ans3 = a.size() - i;
			}
		}
		a.push_back(a_nex);
	}
	
	cout<< ans1<<" "<< ans2<<" "<< ans3<< endl;
	
	return true;
}

int main(){
	cout.setf(ios::fixed);
	cout.precision(10);
	while(solve());

	return 0;
}

 