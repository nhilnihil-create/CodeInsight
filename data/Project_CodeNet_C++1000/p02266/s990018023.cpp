#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
	int a,sum = 0,i=0;
	char s[20010];
	stack<int> S;
	stack<pair<int,int> > S1;
	vector<int> res;
	scanf("%s",s);
	while(s[i]){
		if(s[i]=='\\') S.push(i);
		else if(s[i]=='/'&&S.size()){
			int j = S.top();S.pop();
			a = i - j;
			sum += a;
			while(S1.size()&&S1.top().first>j){
				a += S1.top().second;S1.pop();
			}
			S1.push(make_pair(j,a));
		}
		i++;
	}
	while(S1.size()){
		res.push_back(S1.top().second);
		S1.pop();
	}
	reverse(res.begin(),res.end());
	int n = res.size();
	cout<<sum<<endl;
	cout<<n;
	for(i=0;i<n;)
		printf(" %d",res[i++]);
	cout<<endl;
	return 0;
}
