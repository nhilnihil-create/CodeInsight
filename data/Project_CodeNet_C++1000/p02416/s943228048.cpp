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

#include <stdlib.h>
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
ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
ll lcm(ll a,ll b){return a/gcd(a,b)*b;}

int main(){
	string s[25565] = {""};
	int x[25565] = {0};
	int i = 0;
	int num;
	do{
		cin >> s[i];
		i++;
	}while(s[i-1] != "0");
	i = 0;
	do{
		for(int j = 0;j < s[i].size();j++){
			x[i] += (int)(s[i][j] - '0');
		}
		cout << x[i] << endl;
		i++;
	}while(s[i] != "0");
}