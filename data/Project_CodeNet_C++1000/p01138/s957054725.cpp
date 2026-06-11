#include<iostream>
#include<vector>
#include<algorithm>
#include<cctype>
#include<utility>
#include<string>
#include<cmath>
#include<cstring>
#include<queue>
#include<map>
#include<cstdio>
#include<climits>

#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define llong long long
#define pb(a) push_back(a)
using namespace std;
typedef pair<int, int> P;
typedef long long int ll;
typedef pair<ll,ll> LLP;
#define INF 1000000007
#define MOD 1000000007

#define ARRAY_MAX 100005

int d[ARRAY_MAX];

int main(){

    int n;
    while(cin >> n,n){
        REP(i,ARRAY_MAX){
            d[i] = 0;
        }
        int h,m,s;
        REP(i,n){
            scanf("%d:%d:%d",&h,&m,&s);
            d[3600*h+60*m+s]++;
            scanf("%d:%d:%d",&h,&m,&s);
            d[3600*h+60*m+s]--;
        }
        REP(i,ARRAY_MAX-1){
            d[i+1] += d[i];
        }
        int ans = 0;
        REP(i,ARRAY_MAX){
            ans = max(ans,d[i]);
        }
        cout << ans << endl;
    }


    return 0;
}
