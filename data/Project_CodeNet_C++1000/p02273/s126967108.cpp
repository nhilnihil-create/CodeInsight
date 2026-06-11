#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<stack>
#include<queue>
#include<list>
#include<set>
#include<cmath>

#define REP(i,n) for(int (i) = 0;(i) < (n);(i)++)
using namespace std;
typedef pair<double,double> P;
int n;

void Koch(P p1,P p2,int n1){
		P s,t,u;
		s.first = (p1.first*2+p2.first)/3;
		s.second = (p1.second*2+p2.second)/3;
		u.first = (p1.first+2*p2.first)/3;
		u.second = (p1.second+2*p2.second)/3;
		t.first = (u.first-s.first)*0.5-(u.second-s.second)*0.8660254+s.first;
		t.second = (u.first-s.first)*0.8660254+(u.second-s.second)*0.5+s.second;
		if(n1 < n){
			Koch(p1,s,n1+1);Koch(s,t,n1+1);Koch(t,u,n1+1);Koch(u,p2,n1+1);
		}else{
			cout << p1.first << " " << p1.second << endl;
			cout << s.first << " " << s.second << endl;
			cout << t.first << " " << t.second << endl;
			cout << u.first << " " << u.second << endl;
		}
}

int main(){
	cin >> n;
	if(n!=0)Koch(P(0,0),P(100,0),1);
	else cout << "0 0" << endl;
	cout << "100 0" << endl;; 
}