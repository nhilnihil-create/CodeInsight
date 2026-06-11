#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};


long solve(int n,vector<long> &a,vector<long> &b){
    long ret=0;
    while(1){
        bool f=false;
        for (int i = 0; i < n; i++) {
            if(a[i]!=b[i]) break;
            if(i==n-1) return ret;
        }
        for (int i = 0; i < n; i++) {
            long t = b[i%n] + b[(i+2)%n];
            if(b[(i+1)%n] > t){
                long k = (b[(i+1)%n] - a[(i+1)%n])/t;
                ret += k;
                b[(i+1)%n] -= t*k;
                if(k) f=true;
            }
        }
        if(!f) return -1;
    }
}


int main(){
    int n;cin >> n;
    vector<long> a(n),b(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < n; i++) {
        cin >> b[i];
        if(b[i]<a[i]){
            puts("-1");
            return 0;
        }
    }
    cout << solve(n,a,b) << endl;
    return 0;
}
