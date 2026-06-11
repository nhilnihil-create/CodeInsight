#include <bits/stdc++.h>
using namespace std;
//#define LOCAL
#define fastIO ios::sync_with_stdio(0), cin.tie(0)
#define endl '\n'
#define forn(i,a,b) for(ll i=a;i<=b;i++)
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
const int MAX = 1e7;
ll a[MAX],b[MAX];
int main(){
fastIO;
#ifdef LOCAL
     freopen("in.txt", "r", stdin);
#endif
ll n,m,k,sumA=0,sumB=0;
cin>>n>>m>>k;
forn(i,1,n){
    int x;
    cin>>x;
    sumA+=x;
    a[i]=sumA;
}
forn(i,1,m){
    int x;
    cin>>x;
    sumB+=x;
    b[i]=sumB;
}
ll c=0;
forn(i,0,n){
    ll res = k-a[i];
   // cout<<res<<endl;
    if(res<0){
        continue;
    }
    ll aux = lower_bound(b,b+m,res)-begin(b);
    if(aux>m || b[aux]>res){
        aux--;
    }
    //cout<<aux<<endl;
    c=max(c,i+aux);
    //cout<<c<<end;¿l;
}
cout<<c<<endl;

}

