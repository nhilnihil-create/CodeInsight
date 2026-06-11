#include<iostream>
#include<string>
#include<queue>
using namespace std;

struct job {
	string name;
	long time;
};

int main() {
	int n, q;
	cin >> n >> q;
	queue<job>l;
	for (int i = 0; i < n; i++){
		job j;
		cin >> j.name >> j.time;
		l.push(j);
	}
	int time = 0;
	while (l.size()){
		job j = l.front();
		l.pop();
		if (j.time <= q) {
			time += j.time;
			cout << j.name << ' ' << time << endl;
		}
		else{
			time += q;
			j.time -= q;
			l.push(j);
		}
	}
}