#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cmath>
#include<cctype>
#include<math.h>
#include<string>
#include<string.h>
#include<stack>
#include<queue>
#include<vector>
#include<utility>
#include<set>
#include<map>
#include<stdlib.h>
#include<iomanip>
#include<complex>

using namespace std;

#define ll long long
#define ld long double
#define EPS 1e-9
#define INF 1e9
#define LINF (ll)INF*INF
#define MOD 1000000007
#define rep(i,n) for(int i=0;i<(n);i++)
#define loop(i,a,n) for(int i=a;i<(n);i++)
#define all(in) in.begin(),in.end()
#define shosu(x) fixed<<setprecision(x)

#define int ll //!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

typedef vector<int> vi;
typedef vector<string> vs;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef pair<int,pii> pip;
typedef vector<pii> vp;
typedef vector<vi> vvi;

int gcd(int a, int b){if(b==0) return a;return gcd(b,a%b);}
int lcm(int a, int b){return a/gcd(a,b)*b;}


signed main(void) {
    int n;
    cin >> n;
    vi a(n,0);
    rep(i,n){
        int t;
        cin >> t;
        t--;
        a[t]++;
    }
    sort(all(a));
    vi sum = a;
    rep(i,n-1)sum[i+1] += sum[i];
    loop(k,1,n+1){
        int ok = 0, ng = n/k+1;
        while(ng - ok > 1){
            int mid = (ok + ng)/2;
            //Σmin(ai, mid) >= mid*k ならmidはok
            //aiは昇順なので、mid以上になるiを探す
            int ind = lower_bound(all(a),mid) - a.begin();
            int tmp = (n - ind)*mid;
            if(ind > 0)tmp += sum[ind-1];
            if(tmp >= mid*k)ok = mid;
            else ng = mid;
        }
        cout << ok << endl;
    }
}
