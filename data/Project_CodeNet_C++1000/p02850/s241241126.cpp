#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>
#include <string>
#include <queue>
#include <map>
 
using namespace std;


int main()
{ 
	queue<int> que;
	vector<int> arr[100001];
	int n;
	cin>>n;
	int arr2[100000][2];
	int arr3[100001];
    int arr4[100001];
	for(int i=0;i<100001;i++){arr3[i]=-1;arr4[i]=0;}
	map<pair<int,int>,int> map;
	for(int i=0;i<n-1;i++){
		cin>>arr2[i][0]>>arr2[i][1];
		arr[arr2[i][0]].push_back(arr2[i][1]);
		arr[arr2[i][1]].push_back(arr2[i][0]);
	}
	int num;
	num=arr[1].size();
	for(int i=2;i<=n;i++){
		int cur=arr[i].size();
		if(cur>num)num=cur;
	}
	cout<<num<<endl;
	que.push(1);
  	arr4[1]=1;
	arr3[1]=0;
	int cur;
	while(!que.empty()){
		cur=que.front();
		que.pop();
		int clo=arr3[cur];
		for(int i=0;i<arr[cur].size();i++){
			if(!arr4[arr[cur][i]]){
				que.push(arr[cur][i]);
				clo=clo%num+1;
				arr3[arr[cur][i]]=clo;
              	arr4[arr[cur][i]]=1;
				map.insert(pair<pair<int,int>,int>(make_pair(cur,arr[cur][i]),clo));
			}
		}
	}
	for(int i=0;i<n-1;i++){
		if(!map.count(make_pair(arr2[i][0],arr2[i][1]))){
			int c=arr2[i][0];
			arr2[i][0]=arr2[i][1];
			arr2[i][1]=c;
		}
		cout<<map.at(make_pair(arr2[i][0],arr2[i][1]))<<endl;
	}
	return 0;
}


	
