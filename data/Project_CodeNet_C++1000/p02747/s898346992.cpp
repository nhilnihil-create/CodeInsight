#include<bits/stdc++.h>
#include<iostream>
#include<bitset>
using namespace std;


#define all(x) (x).begin(),(x).end()

#define FOR(i,x,n)for(int i=(x);i<(n);i++)
#define FOR_R(i,x,n) for(int i=(n-1);i>=(x);i--)
#define REP(i, n) FOR(i, 0, n)
#define REP_R(i, n) FOR_R(i, 0, n)

using ll = long long;
typedef long long ll;
typedef long long int64;
typedef long long lint;
typedef long long lli;



//bit

const unsigned int BIT_FLAG_0 = (1 << 0); // 0000 0000 0000 0001
const unsigned int BIT_FLAG_1 = (1 << 1); // 0000 0000 0000 0010
const unsigned int BIT_FLAG_2 = (1 << 2); // 0000 0000 0000 0100
const unsigned int BIT_FLAG_3 = (1 << 3); // 0000 0000 0000 1000
const unsigned int BIT_FLAG_4 = (1 << 4); // 0000 0000 0001 0000
const unsigned int BIT_FLAG_5 = (1 << 5); // 0000 0000 0010 0000
const unsigned int BIT_FLAG_6 = (1 << 6); // 0000 0000 0100 0000
const unsigned int BIT_FLAG_7 = (1 << 7); // 0000 0000 1000 0000




////////////////////////////////////////////////////////////////
	 
int main(){

	string a;
  	cin >>a;
  	FOR(i,0,a.size()-1){if(i%2==1)continue; if(a[i]!='h'||a[i+1]!='i'){cout << "No" << endl; return 0;}}
  	if(a.size()%2==1){cout << "No" << endl;return 0;}
	cout << "Yes" << endl;
  return 0;
}
