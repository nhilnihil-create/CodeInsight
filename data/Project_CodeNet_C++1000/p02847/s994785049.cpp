#include <bits/stdc++.h>
#include <stdio.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
#define FOR(i, a, b) for (int i=a; i<(b); i++)
#define range(a) a.begin(), a.end()
#define endl "\n"
#define Yes() cout << "Yes" << endl
#define No() cout << "No" << endl
const unsigned long long mod = 1e9 + 7;
const long long INF = 1LL<<60;
void chmin(long long &a, long long b) { if (a > b) a = b; }
void chmax(long long &a, long long b) { if (a < b) a = b; }

int main(void){
	ios::sync_with_stdio(0);
	cin.tie(0);
	string S;		cin>>S;
	if(S=="SUN")	cout<<"7"<<endl;
	else if(S=="MON")	cout<<"6"<<endl;
	else if(S=="TUE")	cout<<"5"<<endl;
	else if(S=="WED")	cout<<"4"<<endl;
	else if(S=="THU")	cout<<"3"<<endl;
	else if(S=="FRI")	cout<<"2"<<endl;
	else cout<<"1"<<endl;


    return 0;
}

