#include <bits/stdc++.h>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> p(n,0),q(n,0);
	for(int i=0;i<n;i++)cin >> p[i];
	for(int i=0;i<n;i++)cin >> q[i];

	double d1=0,d2=0,d3=0,di=0;
	for(int i=0;i<n;i++){
		double dis;
		dis=p[i]>q[i] ? p[i]-q[i] : q[i]-p[i];
		d1+=dis;
		d2+=pow(dis,2.0);
		d3+=pow(dis,3.0);
		di =max(di,dis);
	}
	d2=sqrt(d2);
	d3=pow(d3,1/3.0);
	printf("%f\n%f\n%f\n%f\n",d1,d2,d3,di);

	return 0;
}