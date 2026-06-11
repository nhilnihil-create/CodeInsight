#include<iostream>

int main()
{
	int n;

	std::cin >> n;

	double x1,y1,x2,y2,x3,y3,x4,y4;

	for(int i=0;i<n;++i)
	{
		std::cin >> x1 >> y1 >> x2 >> y2 >> x3 >> y3 >> x4 >> y4;

		double m1 = (y1-y2)/(x1-x2);

		double m2 = (y3-y4)/(x3-x4);

		std::cout <<  (m1==m2 ? "YES":"NO") << '\n';
	}
}