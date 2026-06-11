#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e7+5;
bool p[maxn];
int p1[maxn],cnt=0,top;
ll a,b;
ll n,st[20];

void init(int n){
    for(int i=2;i<=n;i++){
        if(!p[i])p1[++cnt]=i;
        for(int j=1;j<=cnt&&p1[j]*i<=n;j++){
            p[p1[j]*i]=1;
            if(i%p1[j]==0)break;
        }
    }
}
ll mysqrt(ll x){
	ll l=1,r=maxn;
	while(l<r){
		ll mid=(l+r)>>1;
		if(mid*mid<x)l=mid+1;
		else r=mid;
	}
	return l;
}

void f(ll x){
    top=1;
    while(x>1){
     int k=mysqrt(x);
     bool f=0;
     for(int i=1;p1[i]<=k;i++){
        int tmp=0;
        while(x%p1[i]==0){
            x/=p1[i];tmp++;
        }
        if(tmp){
            st[++top]=tmp;f=1;
        }
     }

     if(!f){
        st[++top]=1;x/=x;
     }

    }
}
ll gcd(ll a,ll b){
    return b==0?a:gcd(b,a%b);
}
int main(){
    init(2e6);
    cin>>a>>b;

    ll g = gcd(a,b);


    f(g);

    printf("%d\n",top);

    return 0;
}

