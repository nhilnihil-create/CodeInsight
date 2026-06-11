#include<bits/stdc++.h>
using namespace std;

int main(){
	int N, M;
	while(cin >> N >> M){
		priority_queue<int, vector<int>, less<int> > q;
		long long int sum = 0;
		for(int i=0; i<N; i++){
			int temp;
			cin >> temp;
			q.push(temp);
		}
		for(int i=0; i<M; i++){
			int temp = q.top();
			q.pop();
			temp /= 2;
			q.push(temp);
		}
		while(!q.empty()){
			sum += q.top();
			q.pop();
		}
		cout << sum << endl;
	}
}