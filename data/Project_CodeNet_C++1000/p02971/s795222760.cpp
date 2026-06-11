#include <bits/stdc++.h>

using namespace std;
#define rep(i,n) for(long long i=0; i<(long long)(n);i++)
//rep…「0からn-1まで」の繰り返し
#define rep2(i,s,n) for(long long i=s; i<=(long long)(n);i++)
//rep2…「sからnまで」の繰り返し
#define repr(i,s,n) for(long long i=s;i>=(long long)(n);i--)
//repr…「ｓからnまで」の降順の繰り返し

typedef long long ll;

const int inf = 1e9+7;
const int mod = 1e9+7;


int main(){
    int n;
    cin>>n;

    vector<int>a(n+2);
    rep2(i,1,n)cin>>a[i];

    vector<int>l(n+2),r(n+2);
    l[0]=a[0];
    r[n+1]=a[n+1];

    rep2(i,1,n+1)l[i]=max(l[i-1],a[i]);
    repr(i,n,1)r[i]=max(r[i+1],a[i]);

    rep2(i,1,n){
        cout<<max(l[i-1],r[i+1])<<endl;
    }

}
