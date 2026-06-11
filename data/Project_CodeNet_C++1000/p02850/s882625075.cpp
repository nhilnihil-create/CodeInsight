//============================================================================
// Name        : d.cpp
// Author      :
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include<vector>
using namespace std;

int main() {
	int n;cin>>n;
	vector<int> a(n),b(n);
	vector<vector<pair<int,int>>> e(n);
	for(int i=0;i<n-1;i++){
		cin>>a[i]>>b[i];
		a[i]--;b[i]--;
		e[a[i]].push_back(make_pair(b[i],i));
		e[b[i]].push_back(make_pair(a[i],i));
	}
	int ansnum=0;
	for(int i=0;i<n;i++){
		ansnum=max(ansnum,int(e[i].size()));
	}
	vector<int> anse(n-1,-1);
	vector<int> c(n);

	vector<int> stack;
	stack.push_back(0);
	while(stack.size()){
		int tempnode=stack.back();
		stack.pop_back();
		int color=1;
		for(int i=0;i<e[tempnode].size();i++){
			int tempe=e[tempnode][i].second;
			if(anse[tempe]==-1){
				if(color==c[tempnode])color++;
				anse[tempe]=color;
				c[e[tempnode][i].first]=color;
				stack.push_back(e[tempnode][i].first);
				color++;
			}
		}
	}
	cout<<ansnum<<endl;
	for(int i=0;i<n-1;i++){
		cout<<anse[i]<<endl;
	}


	return 0;
}
