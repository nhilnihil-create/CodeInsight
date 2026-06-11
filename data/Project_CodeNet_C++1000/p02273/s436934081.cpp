#include <iostream>
#include <cmath>
using namespace std;

struct TCoordinate
{
	double X;
	double Y;
};

TCoordinate GetSplitMiddle(TCoordinate A, TCoordinate B)
{
	TCoordinate C = {(A.X + B.X) / 2, (A.Y + B.Y) / 2};
	C.X += (sqrt(3) / 6) * (A.Y - B.Y);
	C.Y += (sqrt(3) / 6) * (B.X - A.X);
	return C;
}

void StdOutput(const TCoordinate& Point)
{
	cout << Point.X  << ' ' << Point.Y  << endl;
}

void Koch(int n, const TCoordinate& Start, const TCoordinate& End)
{
	if(n == 0){
		return;
	}
	n--;
	
	TCoordinate SplitStart  = { (2 * Start.X + End.X) / 3, (2 * Start.Y + End.Y) / 3};
	TCoordinate SplitMiddle = GetSplitMiddle(Start, End);
	TCoordinate SplitEnd    = { (Start.X + 2 * End.X) / 3, (Start.Y + 2 * End.Y) / 3};
	
	Koch(n, Start,       SplitStart);
	StdOutput(SplitStart);
	Koch(n, SplitStart,  SplitMiddle);
	StdOutput(SplitMiddle);
	Koch(n, SplitMiddle, SplitEnd);
	StdOutput(SplitEnd);
	Koch(n, SplitEnd,    End);
}

int main()
{
	//??????2?????¨??°???????????°??????????????\???????????????????????????????§?????????????????????¨???
	int n;
	cin >> n;
	TCoordinate Start = {  0, 0};
	TCoordinate End   = {100, 0};
	StdOutput(Start);
	Koch(n, Start, End);
	StdOutput(End);
	return 0;
}