#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

double MM = sqrt(3.0)/2.0; 

void f(int n, double a1, double a2, double b1, double b2){
	if(n == 0) return;
	double c1=(b1-a1)/3.0, c2=(b2-a2)/3.0;
	double top1 = 0.5*c1-MM*c2, top2=MM*c1+0.5*c2;
	double s1 = c1+a1, s2 = c2+a2;
	
	f(n-1, a1, a2, s1, s2);
	cout << s1 << " "<< s2 << endl;
	f(n-1, s1, s2, s1+top1, s2+top2);
	cout << s1+top1 << " "<< s2+top2 << endl;
	f(n-1, s1+top1, s2+top2, s1+c1, s2+c2);
	cout << s1+c1 << " "<< s2+c2 << endl;
	f(n-1, s1+c1, s2+c2, b1, b2);
}


int main(){
	int n;
	cin >> n;
	cout << 0 << " "<< 0<<endl;
	f(n, 0, 0, 100, 0);
	cout << 100 << " "<< 0<<endl;
	return 0;
}