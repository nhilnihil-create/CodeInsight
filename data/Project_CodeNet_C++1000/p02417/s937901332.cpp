#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <string>

#define ll long long
#define vvi vector< vector<int> >
#define All(X) X.begin(),X.end()
#define REP(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main(){
	int counter[30]={0};
	char s;
	while(scanf("%c",&s)!=EOF){
		if(('a'<=s)&&(s<='z')) counter[s-'a']++;
		if(('A'<=s)&&(s<='Z')) counter[s-'A']++;

	}
	REP(i,26){
		char c='a'+i;
		cout << c << " : "<<counter[i]<<endl;
	}
	return 0;
}