#include <bits/stdc++.h>

using namespace std;

class D3
{
public:
	long double X , Y , Z , EPS;

	D3(long double , long double , long double);
	bool operator== (D3 Partner);
	D3 operator*(long double);
	D3 operator/(long double);
};

class Point :private D3
{
public:
	Point(long double , long double , long double);
	long double getX();
	long double getY();
	long double getZ();

	bool operator== (Point);
	long double S_point(Point , Point);
};

class Vec
{
private:
	Point SP;//Starting Point ?§????
	D3 D;//Direction ??????

	Vec(D3 Direction_ , Point SP_);
public:
	Vec(long double x_ , long double y_ , long double z_ , Point);
	Vec operator+(Vec Partner);
	Vec operator*(Vec Partner);
	Vec operator*(long double ld);
	Vec operator-(Vec Partner);
	Vec operator/(Vec Partner);
	Vec operator/(long double);
	bool operator== (Vec);
	Vec Cross_product(Vec);
	double Inner_product(Vec);
	Vec(Point A , Point B);
	Point getSP();
	Point getGP();
	D3 getD();
	long double length();
	Vec Unit_vec();
	Vec Inverse_vec();
	Vec Reverse_vec();
	bool Vertical(Vec);
	bool Parallel(Vec);
	long double S_vec(Vec);
};


//D3

D3::D3(long double x_ = 0.0L , long double y_ = 0.0L , long double z_ = 0.0L)
{
	X = x_;
	Y = y_;
	Z = z_;
	EPS = 1e-9L;
}

bool D3::operator== (D3 Partner)
{
	return abs(X - Partner.X) < EPS&&abs(Y - Partner.Y) < EPS&&abs(Z - Partner.Z) < EPS;
}

D3 D3::operator*(long double ld)
{
	return D3(X*ld , Y*ld , Z*ld);
}

D3 D3::operator/(long double ld)
{
	return  *this*( ld*-1.L );
}


//Point

Point::Point(long double x_ = 0.0L , long double y_ = 0.0L , long double z_ = 0.0L)
{
	X = x_;
	Y = y_;
	Z = z_;
}

//x??§?¨??????????
long double Point::getX()
{
	return X;
}

//y??§?¨??????????
long double Point::getY()
{
	return Y;
}

//z??§?¨??????????
long double Point::getZ()
{
	return Z;
}

bool Point::operator== (Point Partner)
{
	return D3(*this) == D3(Partner);
}
//??????????????¢???????±???????
long double Point::S_point(Point B , Point C)
{
	Vec AB(*this , B) , AC(*this , C);
	return AB.S_vec(AC);
}


//Vec

//??????????????¨?§???????????????????????????????
Vec::Vec(D3 Direction_ , Point SP_)
{
	D = Direction_;
	SP = SP_;
}

//?§??????¨???????????????????????????????????????????????????
Vec::Vec(long double x_ = 0.0L , long double y_ = 0.0L , long double z_ = 0.0L , Point SP_ = Point())
{
	*this = Vec(D3(x_ , y_ , z_) , SP_);
}

Vec Vec::operator+(Vec Partner)
{
	return Vec(D.X + Partner.D.X , D.Y + Partner.D.Y , D.Z + Partner.D.Z , SP);
}

Vec Vec::operator*(Vec Partner)
{
	return Vec(D.X * Partner.D.X , D.Y * Partner.D.Y , D.Z * Partner.D.Z , SP);
}

Vec Vec::operator*(long double ld)
{
	return Vec(D*ld , SP);
}

Vec Vec::operator-(Vec Partner)
{
	return *this + ( Partner*( -1.L ) );
}


Vec Vec::operator/(Vec Partner)
{
	return Vec(D.X / Partner.D.X , D.Y / Partner.D.Y , D.Z / Partner.D.Z , SP);
}

Vec Vec::operator/(long double ld)
{
	return *this*( 1.L / ld );
}

bool Vec::operator== (Vec Partner)
{
	return D == Partner.D&&SP == Partner.SP;
}

//??????
Vec Vec::Cross_product(Vec Partner)
{
	return Vec(D.Y*Partner.D.Z - D.Z*Partner.D.Y , D.Z*Partner.D.X - D.X*Partner.D.Z , D.X*Partner.D.Y - D.Y*Partner.D.X);
}

//??????
double Vec::Inner_product(Vec Partner)
{
	return D.X*Partner.D.X + D.Y*Partner.D.Y + D.Z*Partner.D.Z;
}

//???????????????????????????????????????
Vec::Vec(Point A , Point B)
{
	*this = Vec(A.getX() - B.getX() , A.getY() - B.getY() , A.getZ() - B.getZ() , A);
}

//?§?????????????
Point Vec::getSP()
{
	return SP;
}

//???????????????
Point Vec::getGP()
{
	return Point(SP.getX() + D.X , SP.getZ() + D.Z , SP.getZ() + D.Z);
}

//???????????????
D3 Vec::getD()
{
	return D;
}

//???????????????
long double Vec::length()
{
	return sqrtl(D.X*D.X + D.Y*D.Y + D.Z*D.Z);
}

//??????????????????(??????1)?????????
Vec Vec::Unit_vec()
{
	return Vec(*this) / ( *this ).length();
}

//????????????????????????(?§??????????????????????)
Vec Vec::Inverse_vec()
{
	return ( *this )*-1.L;
}

//????????????????????????(?§??????¨???????????\????????????)
Vec Vec::Reverse_vec()
{
	return Vec(( *this ).Inverse_vec().getD() , ( *this ).getGP());
}

//?????´????????????
bool Vec::Vertical(Vec Partner)
{
	return ( *this ).Inner_product(Partner) == 0;
}

//??????????????????
bool Vec::Parallel(Vec Partner)
{
	return ( *this ).Unit_vec().getD() == Partner.Unit_vec().getD() || ( *this ).Unit_vec().Inverse_vec().getD() == Partner.Unit_vec().getD();
}

//???????§????2????????????????????¢???????±???????
long double Vec::S_vec(Vec B)
{
	//if(( ( *this ).getSP() == B.getSP() ))
	{
		Vec G = ( *this ).Cross_product(B);
		return sqrtl(G.Inner_product(G)) / 2.L;
	}
	if(( *this ).getGP() == B.getSP())
	{
		return ( *this ).Reverse_vec().S_vec(B);
	}
	if(( *this ).getSP() == B.getGP())
	{
		return ( *this ).S_vec(B.Reverse_vec());
	}
	if(( *this ).getGP() == B.getGP())
	{
		return ( *this ).Reverse_vec().S_vec(B.Reverse_vec());
	}

	return -1.L;
}

int main()
{
	long double xA , yA , xB , yB , xC , yC , xD , yD;
	while(cin >> xA >> yA >> xB >> yB >> xC >> yC >> xD >> yD)
	{
		Vec AB(Point(xA , yA) , Point(xB , yB)) , AC(Point(xA , yA) , Point(xC , yC)) , BC(Point(xB , yB) , Point(xC , yC));
		Vec AD(Point(xA , yA) , Point(xD , yD)) , BD(Point(xB , yB) , Point(xD , yD)) , CD(Point(xC , yC) , Point(xD , yD));
		//cout << abs(AD.S_vec(BD) + BD.S_vec(CD) + CD.S_vec(AD) - AB.S_vec(AC)) << endl;
		if(abs(AD.S_vec(BD) + BD.S_vec(CD) + CD.S_vec(AD) - AB.S_vec(AC)) < D3().EPS)
		{
			cout << "YES" << endl;
		} else
		{
			cout << "NO" << endl;
		}

	}
}