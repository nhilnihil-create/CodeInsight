#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

ll gcd(ll x,ll y) {return y ? gcd(y,x%y) : x;}
ll lcm(ll x, ll y) {return x/gcd(x,y)*y;}

int c[1000010];

int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    map<int,int> m;
    rep(i,n){
        cin>>a[i];
        c[a[i]]++;
    }

    bool ok2=true;
    for(int i=2;i<1000005;i++){
        int cnt=0;
        for(int j=i;j<1000005;j+=i) cnt+=c[j];
        if(cnt>1){
            ok2=false;
            break;
        }
    }

    int g=0;
    rep(i,n) g=gcd(g,a[i]);

    if(ok2){
        cout<<"pairwise coprime"<<endl;
    }
    else if(g==1){
        cout<<"setwise coprime"<<endl;
    }
    else{
        cout<<"not coprime"<<endl;
    }

}
