//#include <bits/stdc++.h>
#include <iostream>
#include <vector>
#include <stack>
#include <set>
#include <queue>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <bitset>
using namespace std;

#define ll long long int
#define pb push_back
#define FastIO cin.sync_with_stdio(false),cin.tie(NULL)
#define file freopen("input.txt", "r", stdin),freopen("output.txt", "w", stdout)

ll max(ll a, ll b){
    if(a>b) return a;
    return b;}

ll min(ll a, ll b){
    if(a<b) return a;
    return b;}

const ll N = 1e6 + 5, INF = 1e18, MOD = 1e9 + 7, M = 6000;
int a[N], b[N];
bool c[N];
vector<int> prm;

void f(int n){
	int sq = sqrt(n);
	for(int i = 0; prm[i] <= sq; i++){
		if(n % prm[i] == 0){
			while(n % prm[i] == 0)n /= prm[i];
			b[ prm[i] ]++;
		}
	}
	if(n > 1)b[n]++;
}

int main(){
	FastIO;
	
	for(int i = 2; i < N; i++){
		if(!c[i]){
			for(int j = i; j < N; j+= i)c[j] = true;
			prm.pb(i);
		}
	}

	int n;
	cin >> n;

	int tp = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];
		if(i)tp = __gcd(tp, a[i]);
		else tp = a[i];
	}

	for(int i = 0; i < n; i++)f(a[i]);

	if(*max_element(b, b+N) > 1 && tp == 1) cout << "setwise coprime";
	else if(tp == 1) cout << "pairwise coprime";
	else cout << "not coprime";


	return 0;
}


