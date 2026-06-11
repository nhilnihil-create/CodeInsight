#include <iostream>
#include <iomanip>
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

void Koch(int n, const TCoordinate &Start, const TCoordinate &End)
{
	if(n == 0){
		return;
	}
	n--;
	
	TCoordinate SplitStart  = { (2 * Start.X + End.X) / 3, (2 * Start.Y + End.Y) / 3};
	TCoordinate SplitMiddle = FindSplitMiddle(Start, End);
	TCoordinate SplitEnd    = { (Start.X + 2 * End.X) / 3, (Start.Y + 2 * End.Y) / 3};
	
	Koch(n, Start,       SplitStart );
	cout << SplitStart.X  << ' ' << SplitStart.Y  << endl;
	
	Koch(n, SplitStart,  SplitMiddle);
	cout << SplitMiddle.X << ' ' << SplitMiddle.Y << endl;
	
	Koch(n, SplitMiddle, SplitEnd   );
	cout << SplitEnd.X    << ' ' << SplitEnd.Y    << endl;
	
	Koch(n, SplitEnd,    End        );
}

int main()
{
	//??????2?????¨??°???????????°??????????????\???????????????????????????????§?????????????????????¨???
	int n;
	cin >> n;
	cout <<   0 << ' ' << 0 << endl;
	Koch(n, {0, 0}, {100, 0});
	cout << 100 << ' ' << 0 << endl;
	return 0;
}