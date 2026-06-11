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
    while(1){
        ll n;
        cin >> n;
        if(n==0) return 0;
        ld s[1000],sum=0;
        REP(i,n){
            cin >> s[i];
            sum += s[i];
        }
        ld m = sum / n;
        //printf("%.8llf\n",sum);
        //printf("%.8llf\n",m);
        sum = 0;
        REP(i,n){
            sum += (ld)pow(s[i]-m,2);
        }
        ld ans = sum/n;
        //printf("%.8llf\n",ans);
        ans = (ld)sqrt(ans);
        printf("%.8llf\n",ans);
    }
}
