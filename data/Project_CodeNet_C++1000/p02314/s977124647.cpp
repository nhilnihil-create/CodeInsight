#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int main() {
	int n,m;
	cin >> n >> m;

	
	int c[m];
	for(int i=0; i<m; i++){
		cin >> c[i];
	}
	
	sort(c,c+m);
	
	if(m==1){ cout << n << endl; return 0;}
	else if(m==2){ cout << n/c[1] + n%c[1] << endl; return 0;}
	else{

	int num[n+1]={0};	//x???(0<=x<=n)??????????????????????????????????????°
	
		
	for(int i=0; i<m; i++){num[c[i]]=1;}
	
	queue<int> que;
	for(int i=0; i<m; i++){que.push(c[i]);}
	while(!que.empty()){
		
		for(int i=0; i<m; i++){
			if(c[i]+que.front()<=n && num[c[i]+que.front()]==0){
				num[c[i]+que.front()]=num[que.front()]+1;
				que.push(c[i]+que.front());
			}
		}
		que.pop();
	}
	
	cout << num[n] << endl;
	}
	return 0;
}