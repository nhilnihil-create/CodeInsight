//By: Luogu@rui_er(122461)
#include <bits/stdc++.h>
using namespace std;

const int a[13] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}; 

int main()
{
	int m, d;
	cin>>m>>d;
	cout<<(a[m]==d?1:0)<<endl;
	return 0;
}