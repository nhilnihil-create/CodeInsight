#include <iostream>
#include <queue>
#include <string>
using namespace std;
int main(){
	int n,q,t,sum=0;
	string name;
	queue< pair<string, int> >que;

	cin >> n >> q;

	for (int i = 0; i < n; i++){
		cin >> name >> t;
		que.push(make_pair(name,t));
		}	

	while (!que.empty()){
		pair<string, int>p = que.front(); que.pop();

		if (p.second <= q){
			sum += p.second;
			cout << p.first << " " << sum << endl;
		}
		else if (p.second > q){
			sum += q;
			que.push(make_pair(p.first, p.second - q));
		}
	}

	return 0;
}