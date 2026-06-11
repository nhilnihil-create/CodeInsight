#include <iostream>
#include <algorithm>
using namespace std;

class Vec2
{
public:
	double x, y;
	Vec2(double x = 0, double y = 0) : x(x), y(y){}
	Vec2(const Vec2& v) : x(v.x), y(v.y){}
	Vec2 operator+(const Vec2& other) const
	{
		return Vec2(x + other.x, y + other.y);
	}
	Vec2 operator-(const Vec2& other) const
	{
		return Vec2(x - other.x, y - other.y);
	}
	double dot(const Vec2& other) const
	{
		return x * other.x + y * other.y;
	}
	double cross(const Vec2& other) const
	{
		return x * other.y - y * other.x;
	}
};

istream& operator>>(istream& stream, Vec2& v)
{
	stream >> v.x >> v.y;
	return stream;
}

class Triangle
{
public:
	Vec2 p1, p2, p3;
	Triangle(Vec2 p1, Vec2 p2, Vec2 p3) : p1(p1), p2(p2), p3(p3){}
	Triangle() : p1(0, 0), p2(0, 0), p3(0, 0){}
	Triangle(const Triangle&  other) : p1(other.p1), p2(other.p2), p3(other.p3){}
	bool isHit(const Vec2& pos) const
	{
		Vec2 a = p2 - p1;
		Vec2 b = p3 - p2;
		Vec2 c = p1 - p3;
		Vec2 A = pos - p1;
		Vec2 B = pos - p2;
		Vec2 C = pos - p3;
		double x = a.cross(A);
		double y = b.cross(B);
		double z = c.cross(C);

		if (x >= 0 && y >= 0 && z >= 0) return true;
		if (x <= 0 && y <= 0 && z <= 0) return true;
		return false;
	}
};

int main()
{
	Triangle t;
	Vec2 p;
	while (cin >> t.p1 >> t.p2 >> t.p3 >> p)
	{
		if (t.isHit(p)) cout << "YES" << endl;
		else cout << "NO" << endl;
	}

	return 0;
}