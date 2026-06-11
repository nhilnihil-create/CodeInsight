#include <bits/stdc++.h>
#include <math.h>

using namespace std;

long long inf=1000000007;
double pi=acos(-1);
queue<pair<double,double>> point;

pair<double,double> mp(double a,double b){
	return make_pair(a,b);
}

void solve(int n){
	if(n==0) return;
	queue<pair<double,double>> que;

	pair<double,double> p1;
	pair<double,double> p2=point.front();
	que.push(p2);

	point.pop();

	while(!point.empty()){
		p1=p2;
		p2=point.front();
		point.pop();

		double sx=(2*p1.first+p2.first)/3;
		double sy=(2*p1.second+p2.second)/3;

		double tx=(p1.first+2*p2.first)/3;
		double ty=(p1.second+2*p2.second)/3;

		double ux=(tx-sx)*cos(pi/3)-(ty-sy)*sin(pi/3)+sx;
		double uy=(tx-sx)*sin(pi/3)+(ty-sy)*cos(pi/3)+sy;

		que.push(mp(sx,sy));
		que.push(mp(ux,uy));
		que.push(mp(tx,ty));
		que.push(p2);
	}

	point=que;

	solve(n-1);
}

int main(){
	int n;
	cin>>n;
	point.push(mp(0,0));
	point.push(mp(100,0));
	solve(n);

	while(!point.empty()){
		cout<<fixed<<setprecision(10)<<point.front().first<<" "<<point.front().second<<endl;
		point.pop();
	}

	return 0;
}

