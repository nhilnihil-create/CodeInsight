#include <iostream>
#include <fstream>
#include <algorithm>
#include <bitset>
#include <cassert>
#include <cctype>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <deque>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define EPS 1e-9
#define INF MOD
#define MOD 1000000007LL
#define fir first
#define iss istringstream
#define sst stringstream
#define ite iterator
#define ll long long
#define mp make_pair
#define rep(i,n) rep2(i,0,n)
#define rep2(i,m,n) for(int i=m;i<n;i++)
#define pi pair<int,int>
#define pb push_back
#define sec second
#define sh(i) (1LL<<i)
#define sz size()
#define vi vector<int>
#define vc vector
#define vl vector<ll>
#define vs vector<string>

string s;

int main(){
	while(getline(cin,s),s!="."){
		stack<int> S;
		int ok=1;
		rep(i,s.sz){
			if(s[i]=='(')S.push(0);
			if(s[i]=='[')S.push(1);
			if(s[i]==')'){
				if(!S.sz||S.top()==1){ok=0;break;}
				S.pop();
			}
			if(s[i]==']'){
				if(!S.sz||S.top()==0){ok=0;break;}
				S.pop();
			}
		}
		cout<<(ok&&!S.sz?"yes":"no")<<endl;
	}
}