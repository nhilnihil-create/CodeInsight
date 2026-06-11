#include<bits/stdc++.h>
using namespace std;

int main()
{
	int a, b, h, m; cin >> a >> b >> h >> m;
	printf("%.10f\n", sqrt(a*a + b*b - 2*a*b*cos((h*30 - m*5.5)*M_PI/180)));
}

