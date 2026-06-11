#include<iostream>

class Circle{
public:
	Circle()
		: m_x(0)
		, m_y(0)
		, m_r(0)
	{}
	int m_x;
	int m_y;
	int m_r;
};

int range(int l,int p, int r){
	int a = p - r;
	int b = p + r;
	if (a < 0)
		return 1;
	if (b > l)
		return 1;
	return 0;

}

int main(){
	int h, w;
	Circle c;
	int flag = 0;
	std::cin >> w;
	std::cin >> h;
	std::cin >> c.m_x;
	std::cin >> c.m_y;
	std::cin >> c.m_r;
	if (range(w, c.m_x, c.m_r))
		flag = 1;
	if (range(h, c.m_y, c.m_r))
		flag = 1;
	if (flag == 1)
		std::cout << "No" << '\n';
	else
		std::cout << "Yes" << '\n';

}