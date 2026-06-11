 
 #include<bits/stdc++.h>

using namespace std;
#define INFS (1LL<<28)
#define INF (1LL<<60)
#define DEKAI 1000000007
#define lp(i,n) for(int i=0;i<n;i++)
#define int long long
#define double long double
#define all(n) n.begin(),n.end()

vector<pair<double,pair<double,double>>> ans;

double max(double a,double b){
	if(a>b)return a;
	else return b;
}

double rot(double x,double y){
	double angle=acos(x/(sqrt(x*x+y*y)));
	angle=angle*180.0/acos(-1);
	if(y<0)angle=360.0-angle;
	return angle;
}

signed main(){
	cout << fixed << setprecision(15);
	int n;
	cin>>n;

	lp(i,n){
		int x,y;
		cin>>x>>y;
      if(x==0 && y==0){continue;}
		ans.push_back({rot(x,y),{x,y}});
	}
	sort(ans.begin(),ans.end());
  n=ans.size();
	lp(i,n){
		ans.push_back(ans[i]);
	}
	double r=0;
	lp(i,n){
		double sum[2]={0,0};
		for(int j=i;j<n+i;j++){
			sum[0]+=ans[j].second.first;
			sum[1]+=ans[j].second.second;
			r=max(r,(double)sqrt(sum[0]*sum[0]+sum[1]*sum[1]));
		}
	}
	cout<<r<<endl;
	return 0;
}
