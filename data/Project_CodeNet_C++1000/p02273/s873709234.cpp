#include <cmath>
#include <iostream>
#include <list>
#include <map>

typedef std::pair<double,double> TPoint;

TPoint GetLeft(TPoint Left,TPoint Right)
{
	return std::make_pair((Left.first * 2 + Right.first) / 3,(Left.second * 2 + Right.second) / 3);
}

void Turn(TPoint& Vector)
{
	double X = (Vector.first - (std::sqrt)(3.) * Vector.second) / 2;
	double Y = ((std::sqrt)(3.) * Vector.first + Vector.second) / 2;
	Vector = std::make_pair(X,Y);
}

TPoint GetCenter(const TPoint& Left,const TPoint& Right)
{
	TPoint Vector = std::make_pair(GetLeft(Left,Right).first - Left.first,GetLeft(Left,Right).second - Left.second);
	Turn(Vector);
	return std::make_pair(GetLeft(Left,Right).first + Vector.first,GetLeft(Left,Right).second + Vector.second);
}

TPoint GetRight(const TPoint& Left,const TPoint& Right)
{
	return std::make_pair((Left.first + Right.first * 2) / 3,(Left.second + Right.second * 2) / 3);
}

typedef std::list<TPoint> TPoints;

void Insert(TPoints& Points,const TPoints::iterator Right)
{
	TPoints::iterator It = Right;
	It--;
	TPoint LeftEdge = *It;
	TPoint RightEdge = *Right;
	It++;
	Points.insert(It,GetLeft(LeftEdge,RightEdge));
	Points.insert(It,GetCenter(LeftEdge,RightEdge));
	Points.insert(It,GetRight(LeftEdge,RightEdge));
}

int main()
{
	int Count = 0;
	std::cin >> Count;
	
	TPoints Points;
	Points.push_back(std::make_pair(0.,0.));
	Points.push_back(std::make_pair(100.,0.));
	
	for(int i=0;i<Count;i++)
	{
		TPoints::iterator It = Points.begin();
		It++;
		while(It != Points.end())
		{
			Insert(Points,It);
			It++;
		}
	}
	
	while(!Points.empty())
	{
		std::cout << Points.front().first << " " << Points.front().second << std::endl;
		Points.pop_front();
	}
	return 0;
}