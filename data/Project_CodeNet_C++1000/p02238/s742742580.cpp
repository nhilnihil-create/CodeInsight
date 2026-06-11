#include <bits/stdc++.h>
using namespace std;
#define r(i,n) for(auto i=0;i<n;i++)
#define s(c) static_cast<int>((c).size())

struct Timestamp{
	int discovered;
	int finished;
};

int main(){
	int n;
	cin >> n;

	set<int> A[n+1];
	bool reached[n+1]{};
	int v1, v2, deg;
	r(i, n){
		cin >> v1 >> deg;

		r(j, deg){
			cin >> v2;
			A[v1].insert(v2);
			//A[v2].insert(v1);
		}
	}

	Timestamp ts[n+1];
	for(int i = 1; i <= n; i++){
		ts[i].discovered = 0;
		ts[i].finished = 0;
	}
	ts[1].discovered = 1;


	int time = 0;
	stack<int> s;

	while(true){
		for (int i = 1; i <= n; i++) {
			if (reached[i])
				continue;
			reached[i] = true;
			s.push(i);
			time++;
			ts[i].discovered = time;
			goto DFS;
		}
		break;

		DFS:;
		while (!s.empty()) {
			v1 = s.top();

			bool hasNext = false;
			for (int v2 : A[v1]) {
				if (!reached[v2]) {
					reached[v2] = true;
					s.push(v2);
					hasNext = true;
					break;
				}
			}

			if (!ts[v1].discovered) {
				time++;
				ts[v1].discovered = time;
			}

			if (!hasNext) {
				time++;
				ts[v1].finished = time;
				s.pop();
			}
		}
	}

	for(int i = 1; i <= n; i++){
		printf("%d %d %d\n", i, ts[i].discovered, ts[i].finished);
	}

	return 0;
}

