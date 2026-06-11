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
	vector<task> taskList(n);
	for(int i = 0; i < n; i++){
		cin>>taskList[i].cost>>taskList[i].deadLine;
	}
	sort(taskList.begin(),taskList.end(),myComp);
	bool ans = true;
	int time = 0;
	for(int i = 0; i < n; i++){
		time += taskList[i].cost;
		if( time > taskList[i].deadLine){
			ans = false;
			break;
		}
	}
	if( ans == true){
		cout<<"Yes"<<endl;
	}else{
		cout<<"No"<<endl;
	}
	return 0;
}

