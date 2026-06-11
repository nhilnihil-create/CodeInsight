#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<stack>
#include<queue>
#include<vector>
#define INF 0x3f3f3f3f
#define ll long long
const int N=1005;
const double c=1e-7;
using namespace std;
int main(){
	long long a;
	double b;
	cin>>a>>b;
	b+=c;
	long long d=b*100;
	long long e=a*d;
	long long f=e/100;
	cout<<f;
}