#include <iostream>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <utility>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <queue>
 
using namespace std;
 
#define pb(n)	push_back(n)
#define mp(n,m) make_pair(n,m)
#define fi 	first
#define se 	second
#define all(r) (r).begin(),(r).end()

#define rep(i,n) for(int i=0; i<(n); i++)
#define repc(i,a,b) for(int i=(a); i<(b); i++)

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
 
const int IMAX=((1<<30)-1)*2+1;
const double EPS=1e-10;
//int mod=1000000007


string t[10]={
	"",
	".,!? ",
	"abc",
	"def",
	"ghi",
	"jkl",
	"mno",
	"pqrs",
	"tuv",
	"wxyz"
};



int main(){
	int n;
	string s;
	cin>>n;
	rep(i,n){
		cin>>s;
		string a;
		rep(j,s.size()){
			if(s[j]!='0'){
				char c=t[s[j]-'0'][0];
				int k=0;
				while(1){
					j++;
					if(j>s.size())break;
					if(s[j]=='0'){
						a+=c;
						break;
					}
					k=(k+1)%t[s[j]-'0'].size();
					c=t[s[j]-'0'][k];
				}
			}
		}
		cout<<a<<endl;
	}
}