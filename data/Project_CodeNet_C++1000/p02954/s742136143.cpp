#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;

int main(){
	string s;
	cin>>s;
	vector<int> dis((int)s.size());
	queue<int> que;
	stack<int> sta;

	char now='R';

	for(int i=0;i<(int)s.size();i++){
		if(s.at(i)==now){
			if(now=='R') que.push(i);
			else sta.push(i);
		}else{
			if(now=='R'){
				while(!que.empty()){
					dis.at(que.front())=que.size();
					que.pop();
				}
				sta.push(i);
			}else{
				while(!sta.empty()){
					dis.at(sta.top())=sta.size();
					sta.pop();
				}
				que.push(i);
			}

			now=s.at(i);
		}
	}

	if(now=='R'){
		while(!que.empty()){
			dis.at(que.front())=que.size();
			que.pop();
		}
	}else{
		while(!sta.empty()){
			dis.at(sta.top())=sta.size();
			sta.pop();
		}
	}

	vector<int> kids((int)s.size(),0);

	for(int i=0;i<(int)s.size();i++){
		if(s.at(i)=='R'){
			int here=i+dis.at(i);
			if(dis.at(i)%2==1) here--;

			kids.at(here)++;
		}else{
			int here=i-dis.at(i);
			if(dis.at(i)%2==1) here++;

			kids.at(here)++;
		}
	}

	for(int i=0;i<(int)s.size();i++){
		cout<<kids.at(i);
		if(i<(int)s.size()-1) cout<<" ";
		else cout<<endl;
	}

	return 0;
}
