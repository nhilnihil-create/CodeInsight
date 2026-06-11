#include<bits/stdc++.h>
using namespace std;
#define pi 2.00*acos(0.00)
int main(){
	ios_base :: sync_with_stdio(false);
	cin.tie(NULL);
	int loh,lom;
	cin>>loh>>lom;
	int h,m;
	cin>>h>>m;
	double mul=(double)h/(double)6+(double)m/(double)360-(double)m/(double)30;
	//cout<<"\n"<<pi/acos(((double)(loh*loh)+(double)(lom*lom)-(double)(4.56425719433005567605
//*4.56425719433005567605))/(2.00*(double)(loh*lom)))<<"\n";
	printf("%.20lf",sqrt((double)(loh*loh)+(double)(lom*lom)-2.00*(double)(loh*lom)*cos(pi*mul)));
	return 0;
}
