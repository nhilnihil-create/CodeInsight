#include <bits/stdc++.h>
using namespace std;
#define r(i,n) for(auto i=0;i<n;i++)
#define s(c) static_cast<int>((c).size())

int main(){
	int n;
	cin >> n;

	set<int> A[n+1];
	int v1, v2, deg;
	r(i, n){
		cin >> v1 >> deg;

		r(j, deg){
			cin >> v2;
			A[v1].insert(v2);
		}
	}

	queue<int> s;
	s.push(1);
	int dist[n+1]{0, 1};

	while(!s.empty()){
		int v1 = s.front(); s.pop();
		for(int v2 : A[v1]){
			if(!dist[v2]){
				s.push(v2);
				dist[v2] = dist[v1]+1;
			}
		}
	}

	for(int i = 1; i <= n; i++)
		printf("%d %d\n", i, dist[i]-1);

	return 0;
}

