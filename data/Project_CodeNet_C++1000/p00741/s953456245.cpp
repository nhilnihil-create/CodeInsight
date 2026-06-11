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
#define All(X) X.begin(),X.end()
#define FOR(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define REP(i,n) for(int i=0;i<(int)(n);i++)
#define pb push_back 
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int data[51][51];
int dx[8] = {-1,-1,0,1,1,1,0,-1};
int dy[8] = {0,1,1,1,0,-1,-1,-1};

int h,w;
bool inrange(int x,int y){
	if(x<0||y<0||x>h-1||y>w-1) return false;
	else return true;
}

bool search(int x,int y){
	bool rst = false;
	if(data[x][y] == 0) return rst;
	else {
		data[x][y] = 0;
		rst = true;
	}
	REP(i,8){
		int nx = x+dx[i];
		int ny = y+dy[i];
		if(!inrange(nx,ny)) continue;
		search(nx,ny);
	}
	return rst;
}

int main(){
	while(1){
		cin >> w >> h;
		if(w==0&&h==0) break;
		int ans = 0;
		REP(i,h) REP(j,w) cin >> data[i][j];
		REP(i,h){
			REP(j,w){
				if(search(i,j)==true) ans++;
			}
		}
		cout << ans << endl;
	}
}