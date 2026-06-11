#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define forn(i,a,b) for(int i=a;i<b;i++)
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

int main(){
fastIO;
#ifdef LOCAL
     freopen("int.txt", "r", stdin);
#endif

int n;
cin>>n;
vector<int> v;
forn(i,0,n-1){
    int x;
    cin>>x;
    v.pb(x);
}
int ans=0;
ans+=v[0]+v[n-2];
//cout<<v[0]<<" "<<v[n-2]<<endl;
forn(i,1,n-1){
   // cout<<v[i]<<" "<<v[i-1]<<endl;
    ans+=min(v[i-1],v[i]);
}
cout<<ans<<endl;
}

