#include <iostream>
#include <iomanip>
#include <list>
#include <cmath>
using namespace std;

struct TCoordinate
{
	double X;
	double Y;
};

TCoordinate FindSplitMiddle(TCoordinate A, TCoordinate B)
{
	TCoordinate C = {(A.X + B.X) / 2, (A.Y + B.Y) / 2};
	C.X += (sqrt(3) / 6) * (A.Y - B.Y);
	C.Y += (sqrt(3) / 6) * (B.X - A.X);
	return C;
}

void Koch(list<TCoordinate> &Point, int n, const list<TCoordinate>::iterator &itrStart, const list<TCoordinate>::iterator &itrEnd)
{
	if(n == 0) return;
	n -= 1;
	
	TCoordinate SplitStart  = { (2 * itrStart->X + itrEnd->X) / 3, (2 * itrStart->Y + itrEnd->Y) / 3};
	TCoordinate SplitMiddle = FindSplitMiddle(*itrStart, *itrEnd);
	TCoordinate SplitEnd    = { (itrStart->X + 2 * itrEnd->X) / 3, (itrStart->Y + 2 * itrEnd->Y) / 3};
	
	auto itr = itrStart;
	itr++;
	Point.insert(itr, SplitStart);
	Point.insert(itr, SplitMiddle);
	Point.insert(itr, SplitEnd);
	itr--;
	auto itrSplitEnd    = itr;
	itr--;
	auto itrSplitMiddle = itr;
	itr--;
	auto itrSplitStart  = itr;
	Koch(Point, n, itrStart,       itrSplitStart );
	Koch(Point, n, itrSplitStart,  itrSplitMiddle);
	Koch(Point, n, itrSplitMiddle, itrSplitEnd   );
	Koch(Point, n, itrSplitEnd,    itrEnd        );
}

void Output(const list<TCoordinate> &Point)
{
	auto itr = Point.begin();
	for(int i = 0; i < Point.size(); i++){
		cout << fixed << setprecision(8) << itr->X << ' ' << itr->Y << endl;
		itr++;
	}
}

int main()
{
	int n;
	cin >> n;
	list<TCoordinate> Point;
	TCoordinate Start = {  0, 0};
	TCoordinate End   = {100, 0};
	Point.push_back(Start);
	Point.push_back(End);
	auto itr = Point.end();
	itr--;
	Koch(Point, n, Point.begin(), itr);
	Output(Point);
	return 0;
}