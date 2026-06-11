#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;

int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> b(n);
	rep(i,n){
		int num;
		cin>>num;
		a[i] = num;
		b[i] = num;
	}
	sort(b.begin(),b.end());
	int count = 0;
	rep(i,n){
		if( a[i] != b[i]) count++;
	}
	if( count <= 2){
		cout<<"YES"<<endl;
	}else{
		cout<<"NO"<<endl;
	}
	return 0;
}
