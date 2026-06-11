#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <functional>
#include <utility>
#include <tuple>
#include <cctype>
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PI 4*atan(1.0)
typedef long long ll;
typedef long double ld;
using namespace std;
int dx[4]={0,0,-1,1};
int dy[4]={-1,1,0,0};
const int SIZE=100050;
//int arr[SIZE]={};
//???????????§???????????¬
//???Binary Indexed Tree
struct BIT{
private:
	int n;
	vector<int> node;
public:
	//?????????v???BIT??§??¨?????????
	BIT(int N){
		node.resize(N+1,0);
		n=N;
	}
	int sum(int i){
		if(!i)
			return 0;
		return node[i]+sum(i-(i&-i));
	}
	void add(int i,int x){
		if(i>n)
			return;
		node[i]+=x;
		add(i+(i&-i),x);
	}
};
//???Binary Indexed Tree
int main(){
	int n,q;
	cin>>n>>q;
	BIT bit(n);
	for(int i=0;i<q;i++){
		int c,x,y;
		cin>>c>>x>>y;
		if(c){
			cout<<bit.sum(y)-bit.sum(x-1)<<endl;
		}
		else{
			bit.add(x,y);
		}
	}
	return 0;
}