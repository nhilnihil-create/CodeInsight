#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define forn(i,a,b) for(ll i=a;i<b;i++)
#define ft first
#define sd second
#define sz size()
#define pb push_back
#define pob pop_back()
#define pf push_front
#define pof pop_front()
#define all(x) (x).begin(), (x).end()
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<char,char> pcc;
typedef pair<double,double> pdd;
typedef pair<long long,long long> pll;
//cout << fixed << setprecision(12) <<x<<endl;
const int MAX=1e5;
int a[MAX];
int main(){
fastIO;
#ifdef LOCAL
     freopen("in.txt", "r", stdin);
#endif

int n;
cin>>n;
int s1=0,s2=0;
cin>>a[0];
forn(i,1,n){
    cin>>a[i];
    a[i]+=a[i-1];
    //cout<<a[i]<<endl;
}
int ans=1e8;
forn(i,0,n-1){
    ans = min(ans,abs(a[i]-(a[n-1]-a[i])));
    //cout<<ans<<endl;
}

cout<<ans<<endl;
}
