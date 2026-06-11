///*
/// https://atcoder.jp/contests/tokiomarine2020/tasks/tokiomarine2020_a
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
const int N =2e6+6;
const int mod = 1e9+7;
void solve(){
    string s;
    cin>>s;
    cout<<s[0]<<s[1]<<s[2]<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
    while(t--)solve();
    return 0;
}
//*/
/*
/// https://atcoder.jp/contests/tokiomarine2020/tasks/tokiomarine2020_b
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
const int N =2e6+6;
const int mod = 1e9+7;
void solve(){
    ll a,v;
    ll b,w;
    ll T;
    cin>>a>>v>>b>>w>>T;
    ll d1 = v*T;
    ll d2 = w*T;
    d2+= abs(b-a);
//    cout<<d1<<" "<<d2<<endl;
    if(d2>d1)cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
    while(t--)solve();
    return 0;
}

*/
/*
/// https://atcoder.jp/contests/tokiomarine2020/tasks/tokiomarine2020_c
#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
#define pb push_back
typedef long long ll;
const int N =2e6+6;
const int mod = 1e9+7;
int a[N];
int b[N];
void solve(){
    int n,k;
    cin>>n>>k;
    for(int i=1;i<=n;i++)a[i] = 0;
    for(int it = 1;it<=min(k,50);it++){
        for(int i=1;i<=n;i++){
            int x = max(1,i-a[i]);
            int y = min(n+1,i+a[i]+1);
            b[x] ++;
            b[y]--;
        }
        for(int i=1;i<=n;i++){
            b[i]+=b[i-1];
            a[i] = b[i];
        }
        for(int i=0;i<=n+1;i++)b[i] = 0;
    }
    for(int i=1;i<=n;i++)cout<<a[i]<<" ";
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int t = 1;
    while(t--)solve();
    return 0;
}
*/
