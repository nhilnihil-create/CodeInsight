#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <functional>
#include <numeric>
#include <iomanip>
#define fi first
#define se second
#define fcout(n) cout<<fixed<<setprecision((n))
#define cinl(str) getline(cin,(str))
using namespace std;
bool value(int y,int x,int R,int C){return 0<=y&&y<R&&0<=x&&x<C;}
typedef pair<int,int> pii;
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long > vll;
typedef vector< vi > vvi;
double pie=acos(-1);
int INF=10000009;
int dx[4] = { 0,-1,0,1 };
int dy[4] = { -1,0,1,0 };
struct dice{
	int top;
	int front;
	int right;
	int left;
	int back;
	int bottom;
	int n;
	void spin(char x){
		if(x=='E'){
			n=top;
			top=left;
			left=bottom;
			bottom=right;
			right=n;
		}
		if(x=='W'){
			for(int i=0;i<3;i++){
				spin('E');
			}
		}
		if(x=='S'){
			n=top;
			top=back;
			back=bottom;
			bottom=front;
			front=n;
		}
		if(x=='N'){
			for(int i=0;i<3;i++){
				spin('S');
			}
		}
		if(x=='R'){
			n=front;
			front=left;
			left=back;
			back=right;
			right=n;
		}
	}
};

int main() {
	int a[6];
	int X[25],Y[25];
	int ans;
	int q;
	for(int i=0;i<6;i++){
		cin>>a[i];
	}
	dice d;
	d.top=a[0];
	d.front=a[1];
	d.right=a[2];
	d.left=a[3];
	d.back=a[4];
	d.bottom=a[5];
	cin>>q;
	for(int i=0;i<q;i++){
		cin>>X[i]>>Y[i];
		for(int j=0;j<4;j++){
			d.spin('R');
			if(d.front==Y[i]) break;
			if(j==3){
				for(int k=0;k<4;k++){
					d.spin('S');
					if(d.front==Y[i]) break;
				}
			}
		}
		for(int j=0;j<4;j++){
			d.spin('E');
			if(d.top==X[i]){
				cout<<d.right<<endl;
				break;
			}
		}
	}
}