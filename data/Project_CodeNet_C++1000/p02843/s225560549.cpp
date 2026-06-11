#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
	int x; cin>>x;
	int p1=100, p2=101, p3=103, p4=103, p5=104, p6=105;
	rep(a,1000){
		if(p1*a>x) break;
		rep(b,1000){
			if(p1*a+p1*b>x) break;
			rep(c,1000){
				if(p1*a+p2*b+p3*c>x) break;
				rep(d,1000){
					if(p1*a+p2*b+p3*c+p4*d>x) break;
					rep(e,1000){
						if(p1*a+p2*b+p3*c+p4*d+p5*e>x) break;
						rep(f,1000){
							if(p1*a+p2*b+p3*c+p4*d+p5*e+p6*f==x){
								cout<<1<<endl;
								return 0;
							}
						}
					}
				}
			}
		}
	}
	cout<<0<<endl;
}