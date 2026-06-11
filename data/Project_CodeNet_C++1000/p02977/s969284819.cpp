#include <iostream>
#include <bits/stdc++.h>
#include <cassert>
#include <climits>
#include <bitset>
#include <stack>
#include <iomanip>
#include <limits>
#include <string>
#include <cmath>
#include <math.h>
#include <algorithm>
#include <string.h>
#include <tuple>
#include <time.h>
#include <random>

using namespace std;

typedef long long ll;
typedef pair<ll,ll> P;

long long int INF = 1e18;
double Pi = 3.1415926535897932384626;

vector<ll> G[500005];
//vector<P> tree[500010];
priority_queue <ll> pql;
priority_queue <P> pqp;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
priority_queue <P,vector<P>,greater<P> > pqps;
//small priority queue
//top pop

int dx[8]={1,0,-1,0,1,1,-1,-1};
int dy[8]={0,1,0,-1,1,-1,-1,1};
char dir[] = "DRUL";
//ll bit[500005];
//↓,→,↑,←


#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<(x)<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define line cout << "----------" << endl;


ll mod = 1000000007;
ll rui(ll number1,ll number2){

    if(number2 == 0){
        return 1;
    }else{
        ll number3 = rui(number1,number2 / 2);
        number3 *= number3;
        number3 %= mod;
        if(number2%2==1){
            number3 *= number1;
            number3 %= mod;
        }
        return number3;
    }
}
ll gcd(ll number1,ll number2){

    if(number1 > number2){
        swap(number1,number2);
    }
    if(number1 == 0 || number1 == number2){
        return number2;
    }else{
        return gcd(number2 % number1,number1);
    }
}
void YES(bool condition){

    if(condition){
        p("YES");
    }else{
        p("NO");
    }
    return;
}
void Yes(bool condition){

    if(condition){
        p("Yes");
    }else{
        p("No");
    }
    return;
}


//ll fact[800005],rfact[800005];
/*
void c3_init(){
    fact[0] = rfact[0] = 1;
    for(ll i=1; i<=800000; i++){
        fact[i] = (fact[i-1]*i) % mod;
    }
	rfact[800000] = rui(fact[800000],mod - 2);
	for(ll i=800000; i>=1; i--){
	   rfact[i-1] = rfact[i] * i;
	   rfact[i-1] %= mod;
	}
	return;}
ll c3(ll n,ll r){
    return (((fact[n] * rfact[r]) % mod) * rfact[n-r]) % mod;}
*/

ll n,m,num,ans,a,b,c,d,e,g,h,w,i,j,k,q;
ll x[300005],y[300005],z[100005];
char s[2005][2005];
ll dp[5000];

void add_edge(ll a,ll b){
	x[num] = a;
	y[num] = b;
	num++;
	return;
}


int main(){
	cin >> n;
	m = n;
	while(m % 2 == 0){
		m /= 2;
	}
	if(m == 1){
		p("No");
	}else{
		p("Yes");
		a = 2;
		b = 3;
		add_edge(b+n,1+n);
		while(b <= n){
			add_edge(a+n,b);
			add_edge(b,1);
			add_edge(1,a);
			add_edge(a,b+n);
			a += 2;
			b += 2;
		}
		c = 1;
		while(c * 2 <= n){
			c *= 2;
		}
		if(n % 2 == 0){
			add_edge(n,c);
			d = n ^ c;
			d = d ^ 1;
			add_edge(2*n,d);
		}
		for(i=0;i<num;i++){
			pe(x[i]);p(y[i]);
		}
	}
	return 0;
}
