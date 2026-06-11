#include<bits/stdc++.h>
using namespace std;
int main(){
	int k;
	cin>>k;
	queue<string>q;
	for(int i=1; i<=9; i++){
		string s;
		s.push_back(i+'0');
		q.push(s);
	}
	while(1){
		k--;
		string curr = q.front();
		q.pop();
		if(k==0){
			cout<<curr;
			return 0;
		}
		int last = curr[curr.length()-1]-'0';
		for(int i=last-1; i<=last+1; i++){
			if(i>=0 && i<=9){
				string temp = curr;
				temp.push_back(i+'0');
				q.push(temp);
			}
		}
	}
}