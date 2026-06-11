#define _USE_MATH_DEFINES
#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Coordinate
{
public:
	double x;
	double y;

	Coordinate(double _x, double _y):x(_x),y(_y){}
	Coordinate():Coordinate(0.0,0.0){}
	Coordinate(int _x, int _y):Coordinate((double)_x, (double)_y) {}

	bool isEnd(){
		return (100.0 == this->x && 0.0 == this->y) ? true : false;
	}
};

inline const Coordinate operator+(const Coordinate& lhs, const Coordinate& rhs) {
	return Coordinate(lhs.x + rhs.x, lhs.y + rhs.y);
}
inline const Coordinate operator-(const Coordinate& lhs, const Coordinate& rhs) {
	return Coordinate(lhs.x - rhs.x, lhs.y - rhs.y);
}

const double sin60 = sin(M_PI / 3);
const double cos60 = 0.5;

void makeKockCueve(const int n, vector<Coordinate>& coordList);

int main() {
	int n;
	vector<Coordinate> coordinateList{{0.0, 0.0}, {100.0, 0.0}};
	cin >> n;

	makeKockCueve(n, coordinateList);

	for(const auto& e : coordinateList) {
		cout << e.x << " " << e.y << endl;
	}
	return 0;
}

void makeKockCueve(const int n, vector<Coordinate>& coordList) {
	if(0 == n) { return; }

	Coordinate left, midLeft, mid, midRight, right, tmp;
	double _x, _y;
	auto it = coordList.begin();

	while(it < coordList.end()){
		left = coordList[distance(coordList.begin(), it)];
		if(left.isEnd()) { break; }

		right = coordList[distance(coordList.begin(), it) + 1];

		midLeft.x = left.x + (right.x - left.x) / 3;
		midLeft.y = left.y + (right.y - left.y) / 3;

		midRight.x = left.x + (right.x - left.x) / 3 * 2;
		midRight.y = left.y + (right.y - left.y) / 3 * 2;

		tmp = midRight - midLeft;

		mid.x = midLeft.x + cos60 * tmp.x - sin60 * tmp.y;
		mid.y = midLeft.y + sin60 * tmp.x + cos60 * tmp.y;

		it = coordList.insert(it + 1, {midLeft, mid, midRight});
		it += 3;
	}
	makeKockCueve(n - 1, coordList);
}
