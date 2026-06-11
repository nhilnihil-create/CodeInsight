#include <iostream>
#include <cmath>
#include <utility>

void koch(int d, std::pair<double, double> p1, std::pair<double, double> p2){
	if(d == 0) return;
	std::pair<double, double> s;
	s.first = (2*p1.first+1*p2.first)/3.0;
	s.second = (2*p1.second+1*p2.second)/3.0;
	std::pair<double, double> t;
	t.first = (1*p1.first+2*p2.first)/3.0;
	t.second = (1*p1.second+2*p2.second)/3.0;
	std::pair<double, double> u;
	u.first = (t.first-s.first)/2-sqrt(3.0)*(t.second-s.second)/2+s.first;
	u.second = sqrt(3.0)*(t.first-s.first)/2+(t.second-s.second)/2+s.second;
	koch(d-1, p1, s);
	std::cout << s.first << " " << s.second << std::endl;
	koch(d-1, s, u);
	std::cout << u.first << " " << u.second << std::endl;
	koch(d-1, u, t);
	std::cout << t.first << " " << t.second << std::endl;
	koch(d-1, t, p2);
}

int main(){
	int n;
	std::cin >> n;
	std::cout << 0.0 <<  " " << 0.0 << std::endl;
	std::pair<double, double> p1(0.0, 0.0);
	std::pair<double, double> p2(100.0, 0.0);
	koch(n, p1, p2);
	std::cout << 100.0 << " " << 0.0 << std::endl;
	return 0;
}