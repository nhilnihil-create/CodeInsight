#include<iostream>
#include<algorithm>
#include<queue>
#include<utility>
#include<string>

using namespace std;

queue<string> tasksname;
queue<int> taskst;

int main()
{
	cin.tie(0);
	ios::ios_base::sync_with_stdio(false);
	int taskam, q, time = 0;
	cin >> taskam >> q;
	for (int i = 0; i < taskam; ++i) {
		string name;
		int thistask;
		cin >> name >> thistask;
		if (thistask <= q) {
			time += thistask;
			cout << name << " " << time << endl;
			continue;
		}
		time += q;
		tasksname.emplace(name);
		taskst.emplace(thistask - q);
	}
	while (!tasksname.empty()) {
		int tmpt = taskst.front();
		string tmpname = tasksname.front();
		tasksname.pop();
		taskst.pop();
		int n = tmpt - q;
		if (n > 0) {
			tasksname.emplace(tmpname);
			taskst.emplace(n);
			time += q;
		}
		else {
			time += tmpt;
			cout << tmpname << " " << time << endl;
		}
	}
}