#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <iomanip>
#define ll long long
using namespace std;

struct Egn{
	ll X, Y;
	double angle;
	Egn(ll inputtedX, ll inputtedY){
		X=inputtedX, Y=inputtedY;
		if(X==0 && Y==0) angle=0.0;
		else angle=atan2(Y, X);
	}
	bool operator<(const Egn &a){
		return angle < a.angle;
	}
};

int main() {
	int N;
	cin >> N;
	vector<Egn> p;
	for(int i=0; i<N; ++i){
		ll x, y;
		cin >> x >> y;
		p.push_back(Egn(x, y));
	}
	sort(p.begin(), p.end());
	double mx=0.0;
	for(int i=0; i<N; ++i){
		ll nx=0, ny=0;
		for(int j=0; j<N; ++j){
			nx += p[(i+j)%N].X;
			ny += p[(i+j)%N].Y;
			mx=max(mx, pow(nx*nx+ny*ny, 0.5));
		}
	}
	cout << setprecision(20) << mx << endl;
	return 0;
}