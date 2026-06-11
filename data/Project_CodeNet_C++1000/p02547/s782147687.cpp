#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;

struct task{
	int cost;
	int deadLine;
};

bool myComp(task left,task right){
	return (left.deadLine < right.deadLine);
}

int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0; i < n; i++){
		cin>>a[i]>>b[i];
	}
	bool finalAns = false;
	for(int i = 0; i < n - 2; i++){
		if( a[i] == b[i] && a[i+1] == b[i+1] && a[i+2] == b[i+2]){
			finalAns = true;
			break;
		}
	}
	if(finalAns == true){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}

