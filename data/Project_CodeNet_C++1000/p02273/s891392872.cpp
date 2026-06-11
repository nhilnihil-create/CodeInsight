#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <math.h>
using namespace std;
//常に心してかかれ
//簡単なことを簡単にできるように練習する
//びっくりするくらいつまらないことで詰まってることも多い
int n;//問題で設定された呼び出し階層の深さ
class dot{
public:
	double x;
	double y;

	dot(double X,double Y){
		x=X;
		y=Y;
	}
};

void makeDots(dot A,dot B,int m){//m:この関数の呼び出し元の呼び出し階層
	double tmp_x;
	double tmp_y;

	tmp_x = A.x + (B.x - A.x)/3;
	tmp_y = A.y + (B.y - A.y)/3;

	dot P(tmp_x,tmp_y);

	tmp_x = sqrt(3.0)*(B.x - A.x) - (B.y-A.y);
	tmp_y = (B.x - A.x) + sqrt(3.0)*(B.y - A.y);
	tmp_x = tmp_x/(2*sqrt(3.0));
	tmp_y = tmp_y/(2*sqrt(3.0));
	tmp_x +=A.x;
	tmp_y +=A.y;

	dot Q(tmp_x,tmp_y);

	tmp_x = A.x + 2*(B.x - A.x)/3;
	tmp_y = A.y + 2*(B.y - A.y)/3;

	dot R(tmp_x,tmp_y);

	m++;
	if(m == n){
		cout <<A.x <<" " <<A.y <<endl;
		cout <<P.x <<" " <<P.y <<endl;
		cout <<Q.x <<" " <<Q.y <<endl;
		cout <<R.x <<" " <<R.y <<endl;
		return;
	}

	makeDots(A,P,m);
	makeDots(P,Q,m);
	makeDots(Q,R,m);
	makeDots(R,B,m);

}

int main(){
	dot A(0,0);
	dot B(100,0);

	cin >>n;

	if(n == 0){
		cout <<"0.00000000 0.00000000" <<endl;
		cout <<"100.00000000 0.00000000" <<endl;
		return 0;
	}
	makeDots(A,B,0);

	cout <<100 <<" " <<0 <<endl;
	return 0;
}