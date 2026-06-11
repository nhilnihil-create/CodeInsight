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
#define pi 	3.14159265358979323846


int main(){
    ld x1,x2,y1,y2;
    cin >> x1 >> y1 >> x2 >> y2;
    printf("%llf",(ld)sqrt((ld)pow(x2-x1,2)+(ld)pow(y2-y1,2)));
}
