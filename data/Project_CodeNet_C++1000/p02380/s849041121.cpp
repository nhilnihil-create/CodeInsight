#include<stdio.h>
#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<string.h>
#include<math.h>
#include<utility>
#include<map>
using namespace std;
typedef long long int ll;
typedef long double ld;
typedef vector<ll> vi;
typedef vector<string> vs;
typedef pair<ll,ll> P;
typedef vector<P> vp;
#define REP(i,n) for(int i=0;i<n;i++)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define REPR(i,n) for(int i=n-1;i>=0;i--)
#define FORR(i,n,m) for(int i=n-1;i>=m;i--)
#define all(in) in.begin(),in.end()
#define ALL(in,K) in,in+K
#define INF 100000000
#define MOD 100000007
#define SIZE 100005
#define PI 	3.14159265358979323846


int main(){
    ld a,b,c;
    cin >> a >> b >> c;
    ld rad = c*PI/180.00000000;
    ld l = (ld)pow(a,2)+(ld)pow(b,2)-(ld)(2*a*b*(ld)cos(rad));
    l = (ld)sqrt(l);
    printf("%.13llf\n",(ld)(a*b*(ld)sin(rad)/2));
    printf("%.13llf\n",(ld)(a+b+l));
    printf("%.13llf\n",(ld)(b*(ld)sin(rad)));
}
