#include <bits/stdc++.h>
const int M = 1e4+10;
using namespace std;
int cnt;
vector<int> arr,vec[M];
set<int> st;
int in[M];
void go(){
  	while(!st.empty()){
    	int u=*st.begin();
   		st.erase(st.begin());
    	arr.push_back(u);
    	cnt++;
    	for(int i=0;i!=vec[u].size();i++){
      		in[vec[u][i]]--;
      		if(!in[vec[u][i]])
        		st.insert(vec[u][i]);
    	}
  	}
}
main(){
  	int n,m;
  	cin>>n>>m;
 	for(int i=1;i<=m;i++){
		int x,y;
   		cin>>x>>y;
    	vec[x].push_back(y);
  		in[y]++;
  	}
 	for(int i=0;i<n;i++)
    	if(!in[i])
      		st.insert(i);
  	go();
  	for(int i=0;i<n;i++)
		cout<<arr[i]<<endl;
}