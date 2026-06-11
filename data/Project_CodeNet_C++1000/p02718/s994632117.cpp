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
    int n, m; cin >> n >> m;
    vector<int> a(n);
    double sum = 0;
    string ans = "Yes";
    REP(i,0,n) cin >> a[i];
    REP(i,0,n) sum += a[i];
    sort(a.begin(), a.end(), greater<int>());

    int dev = 4*m;
    REP(i,0,m){
        if(a[i]<(sum/dev)){
            ans = "No";
        }
    }
    cout << ans << endl;
    return 0;
}