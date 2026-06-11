#include <iostream>
#include <queue>
using namespace std;

int main(){
	priority_queue<long long int> pq;
	int n,m;
	while(cin>>n>>m){
		while(!pq.empty()){
			pq.pop();
		}
		long long int total = 0;
		for(int i=0;i<n;i++){
			long long int temp;
			cin>>temp;
			pq.push(temp);
		}
		for(int i=0;i<m;i++){
			int temp = pq.top();
			pq.pop();
			pq.push(temp/2);
		}
		while(!pq.empty()){
			total+=pq.top();
			pq.pop();
		}
		cout<<total<<endl;
	}
	return 0;
}