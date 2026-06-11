#include <iostream>
#include <queue>
#include <stack>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <string>
#include <cmath>
#include <complex>
#include <map>
using namespace std;

#define rep(i,n) for(int i=0;i<int(n);++i)
#define ALL(v) (v).begin(),(v).end()
#define PB push_back
#define EPS 1e-8
#define F first
#define S second

static const double PI=6*asin(0.5);
typedef long long ll;
typedef complex<double> CP;
typedef pair<int,int> P;
static const int INF=1<<24;

string s[15];

int main(){
	s[1]=".,!? ";
	s[2]="abc";
	s[3]="def";
	s[4]="ghi";
	s[5]="jkl";
	s[6]="mno";
	s[7]="pqrs";
	s[8]="tuv";
	s[9]="wxyz";
	
	string st;
	int n;
	cin>>n;
	rep(k,n){
		cin>>st;
		P res(0,0);
		//cout<<"size "<<st.size()<<endl;
		rep(i,st.size()){
			if(st[i]!='0'){
				res.F++;
				res.S=st[i]-'0';
			}
			else if(res.S!=0){
				int t;
				if(res.S==1) t=5;
				else if(res.S==7||res.S==9) t=4;
				else t=3;
				cout<<s[res.S][(res.F-1)%t];
				res.F=0;res.S=0;
			}
		}
		if(res.S!=0){
			int t;
			if(res.S==1) t=5;
			else if(res.S==7||res.S==9) t=4;
			else t=3;
			cout<<s[res.S][(res.F-1)%t];
		}
		cout<<endl;
	}
	
	
	return 0;
}