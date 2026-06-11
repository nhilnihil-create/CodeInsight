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
#define pi 3.14159265359
#define shosu(X) fixed << setprecision(X)
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}
 
int main(){

  while(1){
	char hoge[1000];
	int i = 0;

	//	getline(cin, hoge);

	while(1){
	  hoge[i] = getchar();
	  //	  scanf("%c",&hoge[i]);
	  if(hoge[i]=='\n') continue;
	  if(hoge[i]=='.') break;
	  i++;
	}
	if(hoge[0]=='.') break;

	int mini = 0;
	int big = 0;
	bool now[200] = {};
	int b=0;
 //????????§??????????????????

	REP(a,i){
	  if(hoge[a]=='('){
		mini++;
		b++;
		now[b] = false;
	  }else if(hoge[a]==')'){
		if(now[b] == false) {
		  mini--;
		  b--;
		}else{
		  mini = 100;
		  break;
		}
	  }else if(hoge[a]=='['){
		big++;
		b++;
		now[b] = true;
	  }else if(hoge[a]==']'){
		if(now[b] == true){
		  big--;
		  b--;
		}else{
		  big = 100;
		  break;
		}
	  }
	  if(mini < 0||big < 0) break;
	}

	if(mini==0&&big==0) cout << "yes" << endl;
	else cout << "no" << endl;
  }
}