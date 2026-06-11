#include <iostream>
#include <cstring>
#include <algorithm>
#include <list>
#include <map>
#include <cmath>
#include <string>
#include <cstdio>
#include <vector>
 
using namespace std;

typedef long long ll;
typedef long double ld;
#define L(ID) ((ID*2)+1)
#define R(ID) ((ID*2)+2)
#define M(L,R) ((L+R)/2)
#define forr(start,end) for(int i = start; i < end; i++)
#define gap ' '
 
const int MAXN = 1e5+5;
ll n = 0, a[MAXN], BIT[MAXN];

ll largest(ll a, ll b){
	return (a<b)?b:a;
}
int smallest(ll a, ll b){
	if(a < b)return a;
	return b;
}

int main() {
	int a = 0;
	string s;
	cin >> a >> s;
	if(a >= 3200){
		cout << s << endl;
	}
	else{
		cout << "red" << endl;
	}

    return 0;
}	