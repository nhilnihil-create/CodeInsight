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
typedef pair<int,int> P;
LL mod=1000000007;
LL LINF=1LL<<60;
const int INF=1<<30;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};


const int M_N=400000;

struct BIT{
    //1-indexed
    LL bit[M_N+1],n;
    //iまでの総和を返す
    LL sum(int i){
        LL s=0;
        while(i>0){
            s+=bit[i];
            i=i&(i-1);
        }
        return s;
    }
    //iにx加算する
    void add(int i,LL x){
        while(i<=n){
            bit[i]+=x;
            i+=i&-i;
        }
    }

};

int main(){
    int n;cin >> n;
    vector<int> a(n);
    vector<int> b(n+1,0);
    BIT bit;
    bit.n = n+1;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        b[a[i]]++;
    }
    vector<int> c;
    for (int i = 0; i < n+1; i++) {
        if(b[i]>0){
            bit.add(b[i],1);
            int t = b[i];
            while(t--) c.pb(b[i]);
        }
    }
    sort(ALL(c));
    for (int k = 1; k <= n; k++) {
        int l=0,r=n/k+1;
        while(abs(r-l)>1){
            int m = (r + l) / 2;
            int sum = m*(bit.sum(n) - bit.sum(m));
            sum += upper_bound(ALL(c),m) - c.begin();
            if(sum >= k * m) l = m;
            else r = m;
        }
        cout << l << endl;
    }
    return 0;
}

