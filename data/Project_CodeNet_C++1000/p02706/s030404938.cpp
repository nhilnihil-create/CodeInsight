#include <bits/stdc++.h>
using namespace std;

#define lli long long int
#define REP(i,s,l) for(lli i=s;i<l;i++)
#define DEBUG 0
#define INF (1LL<<50)
#define MOD 1000000007
#define rev(v) reverse(v.begin(), v.end());

bool comp(int a, int b){
    return (a<b);
}

int main(){
    int n, m, sum;
    sum = 0;
    cin >> n >> m;
    vector<int> a(m);
    REP(i,0,m) cin >> a[i];

    REP(i,0,m) sum+=a[i];
    if((n-sum)<0) cout << -1;
    else cout << (n-sum);
    cout << endl;
    return 0;
}