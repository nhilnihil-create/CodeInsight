#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll p[70],q[70];
ll a[100500];
int st[70];
ll ans;
ll x;
ll mx;
int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++) {
        scanf("%lld",&a[i]);
        ans = ans^a[i];
    }
    int tot=0;
    for(int i=61;i>=0;i--)
        if(!(ans&(1ll<<i)))
            st[tot++]=i;
    for(int i=n-1;i>=0;i--) {
        ll x = a[i];
        for(int j=0;j<tot;j++) {
                    if((1ll<<st[j])&x) {
                        if(!p[j]) {
                            p[j]=x;
                            break;
                    }
                    else
                        x^=p[j];
                }
        }
    }
    ll a=0;
    for(int i=0;i<tot;i++) {
            if(!(a&(1ll<<st[i]))) {
                a^=p[i];
            }
    }
    cout<<a+(ans^a)<<endl;
}