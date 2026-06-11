#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <queue>
#define rep(i,n) for(int i=0;i<n;i++)
#define ll long long int
#define MAX 1000000007
using namespace std;


double calc_angle(double a, double b, double ang){
	double work;
	if(a == 0 && b == 0)return 0.0;
	if(b > 0) work = acos(a/sqrt(a*a+b*b));
	else work = -acos(a/sqrt(a*a+b*b));

	while(!(ang <= work && work <= ang+2*M_PI)){
		if(work < ang) work += 2*M_PI;
		else work -= 2*M_PI;
	}
	return work;
}

bool cmp(const pair<double,double> a, const pair<double,double> b){
	return calc_angle(a.first,a.second,0) > calc_angle(b.first,b.second,0);
}

int main(void){
	int n;
	cin >> n;
	vector<pair<double,double> > work(n);
	rep(i,n) cin >> work[i].first >> work[i].second;
	sort(work.begin(),work.end(),cmp);


	//rep(i,n)cout << work[i].first << " " << work[i].second << endl;
	double ans = 0;
	rep(i,n){
		double ang = calc_angle(work[i].first,work[i].second,0);
		//cout << "iter:" << i << endl;
		//cout << "x = " << work[i].first << " ,y = " << work[i].second << " ,angle= "<< ang << endl; 
		int j = (i-1+n)%n;
		double wx=work[i].first,wy=work[i].second;
		//cout << "check right:" << endl;
		//cout << "x = " << work[j].first << " ,y = " << work[j].second << " ,angle= "<< calc_angle(work[j].first,work[j].second,ang) << endl; 
		//cout << calc_angle(work[j].first,work[j].second,ang)-ang << endl;
		if(ans < sqrt(wx*wx+wy*wy))ans = sqrt(wx*wx+wy*wy);
		while(calc_angle(work[j].first,work[j].second,ang)-ang <= M_PI && i != j){
			wx += work[j].first;
			wy += work[j].second;
			j = (j-1+n)%n;
			//cout << "check right:" << endl;
			//cout << "x = " << work[j].first << " ,y = " << work[j].second << " ,angle= "<< calc_angle(work[j].first,work[j].second,ang) << endl; 
			//cout << calc_angle(work[j].first,work[j].second,ang)-ang << endl;
			if(ans < sqrt(wx*wx+wy*wy))ans = sqrt(wx*wx+wy*wy);
		}
		//cout << endl;


		j = (i+1)%n;
		//cout << "check left:" << endl;
		//cout << "x = " << work[j].first << " ,y = " << work[j].second << " ,angle= "<< calc_angle(work[j].first,work[j].second,ang-2*M_PI) << endl; 
		//cout << ang - calc_angle(work[j].first,work[j].second,ang-2*M_PI) << endl;
		wx = work[i].first;
		wy = work[i].second;
		while(ang - calc_angle(work[j].first,work[j].second,ang-2*M_PI) <= M_PI && i != j){
			wx += work[j].first;
			wy += work[j].second;
			j = (j+1)%n;
			//cout << "check left:" << endl;
			//cout << "x = " << work[j].first << " ,y = " << work[j].second << " ,angle= "<< calc_angle(work[j].first,work[j].second,ang-2*M_PI) << endl; 
			//cout << ang - calc_angle(work[j].first,work[j].second,ang-2*M_PI) << endl;
			if(ans < sqrt(wx*wx+wy*wy))ans = sqrt(wx*wx+wy*wy);

		}
		//cout << endl;
	}

	printf("%16.16f\n",ans);
	return 0;
}
