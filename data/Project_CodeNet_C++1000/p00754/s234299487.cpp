#include <iostream>
#include <algorithm>
#include <vector>
#include <stack>
#include <queue>
#include <map>
#include <cmath>
#include <string>
#include <sstream>
#include <iomanip>
#include <complex>
using namespace std;

#define ll long long
#define vvi vector< vector<int> >
#define vi vector<int>
#define All(X) X.begin(),X.end()
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back
#define pii pair<int,int>
#define mp make_pair
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
	while(1){
		string in;
		getline(cin,in);
		if(in[0]=='.') break;
		stack<int> a;
		bool flg = false;
		REP(i,in.size()){
			if(in[i]=='(') a.push(1);
			if(in[i]=='[') a.push(2);
			if(in[i]==')'){
				if(!a.empty()){
					if(a.top()!=1) flg = true;
					a.pop(); 
				}else{
					flg = true;
				}
			}
			if(in[i]==']'){
				if(!a.empty()){
					if(a.top()!=2) flg = true;
					a.pop(); 
				}else{
					flg = true;
				}
			}
		}

		if(flg==false){
			if(!a.empty()) flg = true;
		}
		if(flg) cout << "no" << endl;
		else cout << "yes" << endl;
	}
}