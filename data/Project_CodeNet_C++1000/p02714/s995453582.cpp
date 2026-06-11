#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,x,n) for(int i=x; i<(n); i++)
#define all(x) x.begin(),x.end()
typedef long long ll;
ll mod = 1000000007;
ll inf = 1e18;
int main(){

    int n;
    string s;
    cin >> n >> s;
    vector<int> c(n);
    ll count=0;
    rep(i,n){
        if(s[i]=='R') c[i]=0;
        if(s[i]=='G') c[i]=1;
        if(s[i]=='B'){
            c[i]=2;
            count++;
        }
    }
    // cout << count << endl;
    // rep(i,n) cout << c[i];
    // cout << endl;

    ll ans=0;
    rep(i,n){
        if(c[i]!=0) continue;
        // cout << i << endl;
        rep(j,n){
            if(c[j]!=1) continue;
            ans+=count;
            int n1=i,n2=j;
            if(n1>n2) swap(n1,n2);
            int n3=abs(n1-n2);
            // cout << n1 << ' ' << n2 << ' ' << n3 << endl;
            if(n1-n3>=0){
                if(c[n1-n3]==2) ans--;
            }
            if(n2+n3<n){
                if(c[n2+n3]==2) ans--;
            }
            if((n2-n1)%2==0){
                if(c[n1+(n2-n1)/2]==2) ans--;
            }
            // cout << ans << endl;
        }
    }
    cout << ans << endl;
    
    return 0;
}