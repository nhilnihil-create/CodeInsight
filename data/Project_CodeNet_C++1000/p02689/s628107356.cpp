#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;
vector <int> n;

int main(){
	int n,m,t,u,num=0;
	vector <int> h;
	set <int> a;
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>t;
		h.push_back(t);
	}
	for(int i=0;i<m;i++){
		cin>>t>>u;
		if(h[t-1]>=h[u-1]){
			if(!a.count(u)){
				a.insert(u);
				num++;
			}
		}
		if(h[u-1]>=h[t-1]){
			if(!a.count(t)){
				a.insert(t);
				num++;
			}
		}
	}
	cout<<n-num<<endl;
	return 0;
}