#include <bits/stdc++.h>
#define maxn 200100
#define pii pair<int,int>
#define fi first
#define se second
#define ll long long

using namespace std;

int n,a[maxn],b[maxn];
ll ans=0;
set<pii> s;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    //freopen("in.txt","r",stdin);
    cin>>n;
    for (int i=0;i<n;i++) cin>>a[i];
    for (int i=0;i<n;i++) {
        cin>>b[i];
        s.insert(pii(b[i],i));
    }
    /*for (set<pii>::iterator it=s.begin(); it!=s.end(); ++it)
    cout << ' ' << it->fi;
    cout<<endl;*/
    while (!s.empty()) {
        int id = s.rbegin()->se;
        s.erase(--s.end());
        //cout<<s.size()<<" "<<id<<" "<<b[id]<<endl;
        if (a[id]==b[id]) continue;
        ll tmp = b[(id+1)%n] + b[(id-1+n)%n];
        if (b[id]<a[id] || (b[id]-a[id])<tmp) {
            cout<<-1;
            return 0;
        }
        ans += (b[id]-a[id])/tmp;
        if ((b[id]-a[id])%tmp==0) b[id]=a[id];
        else {
            b[id] = b[id] - (b[id]-a[id])/tmp * tmp;
            s.insert(pii(b[id],id));
        }

    }
    cout<<ans;
}
