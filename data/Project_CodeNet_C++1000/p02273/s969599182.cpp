#include <cmath>
#include <iostream>

struct TPoint
{
	double X;
	double Y;
};

TPoint GetLeft(TPoint Left,TPoint Right)
{
	TPoint Result;
	Result.X = (Left.X * 2 + Right.X) / 3;
	Result.Y = (Left.Y * 2 + Right.Y) / 3;
	return Result;
}

void Turn(TPoint& Vector)
{
    double TempX = (Vector.X - (std::sqrt)(3.) * Vector.Y) / 2;
    double TempY = ((std::sqrt)(3.) * Vector.X + Vector.Y) / 2;
    Vector.X = TempX;
	Vector.Y = TempY;
}
 
TPoint GetCenter(const TPoint& Left,const TPoint& Right)
{
    TPoint Vector;
	Vector.X = GetLeft(Left,Right).X - Left.X;
	Vector.Y = GetLeft(Left,Right).Y - Left.Y;
    Turn(Vector);
	TPoint Result;
	Result.X = GetLeft(Left,Right).X + Vector.X;
	Result.Y = GetLeft(Left,Right).Y + Vector.Y;
	return Result;
}
 
TPoint GetRight(const TPoint& Left,const TPoint& Right)
{
	TPoint Result;
	Result.X = (Left.X + Right.X * 2) / 3;
	Result.Y = (Left.Y + Right.Y * 2) / 3;
	return Result;
}

void OutputKochCurve(TPoint Left,TPoint Right,int N)
{
	if(N < 1) return;
	OutputKochCurve(Left,GetLeft(Left,Right),N-1);
	std::cout << GetLeft(Left,Right).X << " " << GetLeft(Left,Right).Y << std::endl;
	OutputKochCurve(GetLeft(Left,Right),GetCenter(Left,Right),N-1);
	std::cout << GetCenter(Left,Right).X << " " << GetCenter(Left,Right).Y << std::endl;
	OutputKochCurve(GetCenter(Left,Right),GetRight(Left,Right),N-1);
	std::cout << GetRight(Left,Right).X << " " << GetRight(Left,Right).Y << std::endl;
	OutputKochCurve(GetRight(Left,Right),Right,N-1);
}

int main()
{
	int N;
	std::cin >> N;
	std::cout << 0 << " " << 0 << std::endl;
	TPoint Left = {0.,0.};
	TPoint Right = {100.,0.};
	OutputKochCurve(Left,Right,N);
	std::cout << 100 << " " << 0 << std::endl;
	return 0;
}