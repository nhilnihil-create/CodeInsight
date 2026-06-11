#include<iostream>
#include<cmath>
#include<iomanip>

#define PI 3.141592

using namespace std;

struct coordinate{
	double x;
	double y;
};

void kock(int n,struct coordinate left,struct coordinate right){
	if (n == 0) return;
	struct coordinate s,t,u;
	s.x = (left.x * 2 + right.x * 1)/3;
	s.y = (left.y * 2 + right.y * 1)/3;
	t.x = (left.x * 1 + right.x * 2)/3;
	t.y = (left.y * 1 + right.y * 2)/3;
	u.x = (t.x - s.x) * cos(PI/3) - (t.y - s.y) * sin(PI/3) + s.x;
	u.y = (t.x - s.x) * sin(PI/3) + (t.y - s.y) * cos(PI/3) + s.y;

	kock(n-1,left,s);
	cout << setprecision(10) << s.x << " " << setprecision(10) << s.y <<  endl;
	kock(n-1,s,u);
	cout << setprecision(10) << u.x << " " << setprecision(10) << u.y <<  endl;
	kock(n-1,u,t);
	cout << setprecision(10) << t.x << " " << setprecision(10) << t.y <<  endl;
	kock(n-1,t,right);
}

int main(){
	int n; cin >> n;
	struct coordinate p1,p2;
	p1.x = 0;
	p1.y = 0;
	p2.x = 100;
	p2.y = 0;
	cout << p1.x << " " << p1.y << endl;
	kock(n,p1,p2);
	cout << p2.x << " " << p2.y << endl;
return 0;
}