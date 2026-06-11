#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstring>
#include<queue>
#include<tuple>
#include<utility>
#include<map>
#include<math.h>
#include<iomanip>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (ll i=a; i<(b); i++)
#define range(a) a.begin(), a.end()
#define endl "\n"
#define Yes() cout << "Yes" << endl
#define No() cout << "No" << endl
using Graph = vector<vector<bool>>;
const unsigned long long mod = 1e9 + 7;
const long long INF = 1LL<<60;
const int dx[4]={1,0,-1,0};
const int dy[4]={0,1,0,-1};
void chmin(long long &a, long long b) { if (a > b) a = b; }
void chmax(long long &a, long long b) { if (a < b) a = b; }

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll H,W,M,max_t=0,max_y=0;	cin>>H>>W>>M;
	vector<pair<ll, ll>> P;
	vector<ll> T(H,0), Y(W,0);
	FOR(i,0,M){
		ll a,b; cin>>a>>b;
		a--; b--;
		T.at(a)++;
		Y.at(b)++;
		max_t = max(max_t, T.at(a));
		max_y = max(max_y, Y.at(b));
		P.push_back(make_pair(a, b));
	}

	sort(range(P));
	//cout<<max_t<<"/"<<max_y<<endl;

	vector<ll> T_0,Y_0;
	FOR(i,0,H){
		if(T.at(i)==max_t) T_0.push_back(i);
	}

	FOR(i,0,W){
		if(Y.at(i)==max_y) Y_0.push_back(i);
	}

	FOR(i,0,T_0.size()){
		FOR(j,0,Y_0.size()){
			if(binary_search(range(P),make_pair(T_0.at(i), Y_0.at(j)))==false){
				cout<<max_t+max_y<<endl;
				return 0;
			} 
		}
	}

	cout<<max_t+max_y-1<<endl;

    return 0;
}

