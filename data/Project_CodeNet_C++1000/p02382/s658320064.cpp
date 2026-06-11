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
    ll n;
    ld ans;
    cin >> n;
    ld x[100],d[100];
    REP(i,n){
        cin >> x[i];
    }
    REP(i,n){
        ld y;
        cin >> y;
        d[i] = abs(x[i]-y);
    }
    ld sum = 0;
    REP(i,n){
        sum += d[i];
    }
    printf("%.8llf\n",sum);

    sum = 0;
    REP(i,n){
        sum += (ld)pow(d[i],2);
        //cout << sum << endl;
    }
    ans = (ld)pow(sum,0.5);
    printf("%.8llf\n",ans);
    sum = 0;
    REP(i,n){
        sum += (ld)pow(d[i],3);
        //cout << sum << endl;
    }
    double num = 1.0/3.0;
    ans = (ld)pow(sum,num);
    printf("%.8llf\n",ans);
    
    ans = 0;
    REP(i,n){
        ans = max(ans,d[i]);
        //cout << ans << endl;
    }
    printf("%.8llf\n",ans);
}
