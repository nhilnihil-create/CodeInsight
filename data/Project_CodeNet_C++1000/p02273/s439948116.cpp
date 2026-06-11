#include <bits/stdc++.h>
using namespace std;
using UL=unsigned int;
using LL=long long;
using ULL=unsigned long long;
#define rep(i,n) for(UL i=0; i<(n); i++)

struct Vec{
	double x,y;
	Vec(double xx,double yy):x(xx),y(yy){}
};

Vec Relate(Vec o, Vec x, Vec p){
	Vec ans{0,0};
    x.x-=o.x; x.y-=o.y;
	ans.x += x.x*p.x; ans.y += x.y*p.x;
	ans.x -= x.y*p.y; ans.y += x.x*p.y;
	ans.x+=o.x; ans.y+=o.y;
	return ans;
}

vector<Vec> buf;

int main(){
	UL N; cin>>N;
	buf.push_back(Vec(0.0,0.0));
	buf.push_back(Vec(100.0,0.0));
	rep(n,N){
		vector<Vec> tmp;
        tmp.push_back(Vec(0.0,0.0));
		rep(i,buf.size()-1){
			tmp.push_back(Relate(buf[i],buf[i+1],Vec(1.0/3.0,0.0)));
			tmp.push_back(Relate(buf[i],buf[i+1],Vec(0.5,sqrt(0.75)/3.0)));
			tmp.push_back(Relate(buf[i],buf[i+1],Vec(2.0/3.0,0.0)));
			tmp.push_back(Relate(buf[i],buf[i+1],Vec(1.0,0.0)));
		}
        buf=move(tmp);
	}
	cout<<fixed<<setprecision(10);
	for(Vec& v:buf){
		cout<<v.x<<" "<<v.y<<endl;
	}
}
