#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;

int main(){
	int n;
	cin >> n;
	vector<pair<pair<double, double>, double>> v;
	v.emplace_back(make_pair(make_pair(0, 0), 0));
	for(int i = 1; i <= n; i++){
		double dist = 100.0 / pow(3, i);
		vector<pair<pair<double, double>, double>> next;
		for(auto &&pp:v){
			pair<double, double> &p = pp.first;
			double angle = pp.second;
			next.emplace_back(make_pair(p, angle));
			next.emplace_back(make_pair(make_pair(p.first += dist * cos(angle), p.second += dist * sin(angle)), angle + M_PI / 3));
			next.emplace_back(make_pair(make_pair(p.first += dist * cos(angle + M_PI / 3), p.second += dist * sin(angle + M_PI / 3)), angle - M_PI / 3));
			next.emplace_back(make_pair(make_pair(p.first += dist * cos(angle - M_PI / 3), p.second += dist * sin(angle - M_PI / 3)), angle));
		}
		v = next;
	}
	v.emplace_back(make_pair(make_pair(100, 0), 0));
	for(auto &&pp:v){
		pair<double, double> &p = pp.first;
		cout << fixed << setprecision(10) << p.first << ' ' << p.second << endl;
	}
	return 0;
}