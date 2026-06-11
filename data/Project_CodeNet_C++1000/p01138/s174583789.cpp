#include<iostream>
#include<string>
#include<sstream>
#include<string.h>
#include<algorithm>

using namespace std;

int timecount[86400];

int stoi(string str){
	stringstream ss;
	int num;
	ss << str;
	ss >> num;
	return num;
}

int hmstot(string str){
	return stoi(str.substr(0,2)) * 3600 + stoi(str.substr(3,2)) * 60 + stoi(str.substr(6,2));
}

int main(){
	while(1){
		memset(timecount, 0,sizeof(timecount));
		int n;
		cin >> n;
		if(n == 0) break;
		
		for(int i = 0;i < n;i++){
			string shms,ghms;
			cin >> shms >> ghms;
			int st,gt;
			st = hmstot(shms);
			gt = hmstot(ghms);
			for(int j = st;j < gt;j++){
				timecount[j]++;
			}
		}
		
		int ans = 0;
		for(int i = 0;i < 86400;i++){
			ans = max(ans,timecount[i]);
		}
		cout << ans << endl;
	}
	return 0;
}
