#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;

class triangle
{
private:
	double a, b, C, S, L, h;
public:
	triangle(double edge1, double edge2, double angle);
	~triangle(){;}
	void calc_area();
	void calc_around();
	void calc_height();
	void print_();

};

triangle::triangle(double edge1, double edge2, double angle)
{
	a = edge1;
	b = edge2;
	C = angle;
}

void triangle::calc_area()
{
	S = (a * b * sin(C)) / 2;
}

void triangle::calc_around()
{
	L = a + b + sqrt(pow(a, 2.0) + pow(b, 2.0) - 2 * a * b * cos(C));
}

void triangle::calc_height()
{
	h = b * sin(C);
}

void triangle::print_()
{
	printf("%lf\n", S);
	printf("%lf\n", L);
	printf("%lf\n", h);	
}



int main(int argc, char const *argv[])
{
	int count = 3;
	double input[3];
	for (int i = 0; i < count; ++i)
	{
		cin >> input[i];
	}
	triangle abc(input[0], input[1], M_PI * input[2] / 180);
	abc.calc_area();
	abc.calc_around();
	abc.calc_height();

	abc.print_();

	return 0;
}