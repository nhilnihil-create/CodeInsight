#include <bits/stdc++.h>

#define st first
#define nd second
#define ll long long
#define ld long double
#define pb push_back
#define emp emplace_back
#define pii pair<int, int>
#define usg unsigned
#define sg signed
#define mp make_pair

using namespace std;

void setIO(){
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
}

const ld PI = 4*atan((ld)1);
const int INF = 1e9+7;

int main(){
	setIO();
	int s, w;
	cin>>s>>w;
	if(s>w) cout<<"safe\n";
	else cout<<"unsafe\n";
}