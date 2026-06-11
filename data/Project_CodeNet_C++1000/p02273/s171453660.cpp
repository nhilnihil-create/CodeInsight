#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>

#define DEG2EAD 0.01745329251994329576923690768489

std::vector< std::pair<double,double> > Koch_Curve(std::pair <double,double>,std::pair <double,double>,int);
std::vector< std::pair<double,double> > Koch_Curve(std::pair <double,double>,std::pair <double,double>,int,int);

int main(int argc, char const *argv[]){
	int n;
	std::cin >> n;
	std::vector< std::pair<double,double> > ans;
	std::pair<double,double> p0,p1;
	p0 = std::make_pair(0.0,0.0);
	p1 = std::make_pair(100.0,0.0);
	ans = Koch_Curve(p0,p1,n);

	for(int i=0; i<ans.size(); i++){
		std::cout << std::fixed;
		std::cout << std::setprecision(8) << ans[i].first << " " << ans[i].second << std::endl;
	}

	return 0;
}


std::vector< std::pair<double,double> > Koch_Curve(std::pair <double,double> Ps, std::pair <double,double> Pe, int N){
	std::vector< std::pair<double,double> > ans;
	ans.push_back(Ps);
	std::vector< std::pair<double,double> > buff = Koch_Curve(Ps,Pe,N,0);
	ans.insert(ans.end(),buff.begin(),buff.end());
	ans.push_back(Pe);
	return ans;
}

std::vector< std::pair<double,double> > Koch_Curve(std::pair <double,double> Ps, std::pair <double,double> Pe, int N, int n){
	double dx = Pe.first - Ps.first;
	double dy = Pe.second - Ps.second;
	std::pair<double,double> mid_0,mid_1,top;
	std::vector< std::pair<double,double> > buff,ans;

	mid_0 = std::make_pair(Ps.first+dx*1.0/3.0,Ps.second+dy*1.0/3.0);
	mid_1 = std::make_pair(Ps.first+dx*2.0/3.0,Ps.second+dy*2.0/3.0);
	
	if(n<N){
		ans = Koch_Curve(Ps,mid_0,N,n+1);
		ans.push_back(mid_0);
		
		double angle = 60.0*DEG2EAD;
		top.first  = mid_0.first  + dx / 3.0 * cos(angle) - dy / 3.0*sin(angle);
		top.second = mid_0.second + dx / 3.0 * sin(angle) + dy / 3.0*cos(angle);

		buff = Koch_Curve(mid_0,top,N,n+1);
		ans.insert(ans.end(),buff.begin(),buff.end());
		
		ans.push_back(top);

		buff = Koch_Curve(top,mid_1,N,n+1);
		ans.insert(ans.end(),buff.begin(),buff.end());

		ans.push_back(mid_1);

		buff = Koch_Curve(mid_1,Pe,N,n+1);
		ans.insert(ans.end(),buff.begin(),buff.end());	
	}
	return ans;
}

