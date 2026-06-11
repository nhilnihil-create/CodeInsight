#include<bits/stdc++.h>

#define swap(type,a,b) {type t; t=a; a=b; b=t;}
#define forN(i,n) for(int i=0;i<n;i++)
#define forS(i,start,n) for(int i=start;i<n;i++)
#define ll long long
#define pb(t,d,n) {t p;int i;forN(i,n){cin>>p;d.push_back(p);}}
#define DOUBLE fixed << setprecision(10)

using namespace std;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int,int> pii;
typedef vector<pair<int,int>> vpii;

int main(){
    int n,m,i,j,cnt;
    
    const long long int MOD = 1e9+7;
    cin>>n>>m;
    vi a(n+1,true);
    bool res=true;
    forN(i,m){
        int tmp;cin >> tmp;
        a[tmp] = false;
        if(!a[tmp-1]) res=false;
    }
    
    vector<ll> fib(n+1);
    fib[0] = 1;
    forN(i,n){
        for(j=i+1;j<=min(n,i+2);j++){
            if(a[j]){
                fib[j]+=fib[i];
                fib[j]%=MOD;
            }
        }
    }
    cout << (res?fib[n]:0) << endl;
}