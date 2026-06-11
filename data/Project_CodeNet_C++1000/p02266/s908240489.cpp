#include <iostream>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <stack>
#include <vector>
using namespace std;
const int INF = 0x3f3f3f3f;

int main(){
	int ans = 0;
	char ch;
	stack<int> s1;
	stack<pair<int, int> > s2;
	for(int i = 0; cin >> ch; i++){
		if(ch == '\\')
			s1.push(i);
		else if(ch == '/' && s1.size() > 0){
			int j = s1.top();
			s1.pop();
			ans += i - j;
			int temp = i  - j;
			while(s2.size() > 0 && s2.top().first > j){
				temp += s2.top().second;
				s2.pop();
			}
			s2.push(make_pair(j, temp));
		}
	}
	vector<int > v;
	while(s2.size() > 0){
		v.push_back(s2.top().second);
		s2.pop();
	}
	reverse(v.begin(), v.end());
	printf("%d\n%d", ans, v.size());
	for(int i = 0; i < v.size(); i++)
		printf(" %d", v[i]);
	printf("\n");
	return 0;
}