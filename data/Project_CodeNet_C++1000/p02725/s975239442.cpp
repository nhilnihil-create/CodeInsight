#include <iostream>
#include <vector>
#define rep(i, n) for(int i = 0; i < n; i++)

using namespace std;

int main(){
	int k, n;
	cin >> k >> n;
	vector<int> a(n);
	vector<int> dis(n);
	rep(i, n) cin >> a.at(i);
	
	dis.at(0) = a.at(0) + (k-a.at(n-1));
	
	int total = dis.at(0);
	int longest_dis = dis.at(0);
	for(int i = 1; i < n; i++){
		dis.at(i) = a.at(i) - a.at(i-1);
		total += dis.at(i);
		longest_dis = (longest_dis < dis.at(i))?dis.at(i):longest_dis;
	}
	cout << total - longest_dis << endl;
	
}