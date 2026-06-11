// file creato da gio il 2020-09-14 17:13:19.374937

#include <bits/stdc++.h>

#ifdef FAST
#pragma GCC optimize("Ofast")
#pragma GCC target("fma,sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,tune=native")
#pragma GCC optimize("unroll-loops")
#endif

#define MOD 1000000007
#define S second
#define F first
#define PB push_back
#define ll long long 

using namespace std;

#define MN 500001
#define LSB(n) n&-n

ll ftree[MN];
int n;


void update(int p,int v){
    while(p<=n){
        ftree[p]+=v;
        p+=LSB(p); 
    }
}

ll sum(int p){
    ll s=0;
    while(p>0){
        s+=ftree[p];
        p-=LSB(p);
    }
    return s;
}

ll sum(int a,int b){return sum(max(a,b))-sum(min(a,b));}

int main(){
    //freopen("output","w",stdout);
    //freopen("input","r",stdin);
#ifdef FAST
    ios::sync_with_stdio(0);
    cin.tie(0);
#endif

    int q;
    cin >> n>>q;
    for(int i=0;i<n;i++){
        int t;
        cin >>t;
        update(i+1,t);
    }
    for(int i=0;i<q;i++){
        int a,b,c;
        cin >>a>>b>>c;
        if(a)
            cout <<sum(b,c)<<endl;
        else
            update(b+1,c);

    }

}
