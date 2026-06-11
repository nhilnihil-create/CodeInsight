#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <queue>

using namespace std;


void solve(int n,int m){
	int dif,s1,s2,tmp,flag;
	vector<int>v1,v2;
	s1=0;
	s2=0;
	for(int i=0;i<n;i++){
		cin >>tmp;
		s1+=tmp;
		v1.push_back(tmp);
	}
	for(int i=0;i<m;i++){
		cin >> tmp;
		s2+=tmp;
		v2.push_back(tmp);
	}
	sort(v1.begin(),v1.end());
	sort(v2.begin(),v2.end());
	dif=s1-s2;
	if(dif%2!=0){
		cout << -1 <<endl;
		return;
	}
	dif = dif/2;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(v1[i]==v2[j]+dif){
				cout << v1[i] << " " << v2[j] << endl;
				return;
			}
		}
	}
	cout << -1 <<endl;
	return ;		
}


int main(){
	int n,m;
	while(1){
		cin >> n >> m;
		if(n==0&&m==0)break;
		solve(n,m);
	}
	return 0;
}