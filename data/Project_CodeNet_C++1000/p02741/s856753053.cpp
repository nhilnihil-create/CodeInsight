//“ In order to be irreplaceable, one must always be different”
#include <bits/stdc++.h>
using namespace std;
# define ll long long
#define endl "\n"
# define pi 3.14159265359
# define str string
# define vll vector<ll>
# define vstr vector<str>
# define vchar vector<char>
# define pb push_back
# define popb pop_back
# define pf push_front
# define popf pop_front
# define sll set<ll>
# define schar set<char>
//find()
//erase(x) removes element x
//erase(position,position)
# define qll queue<ll>
# define qstr queue<str>
//front(),back()
# define stll stack<ll>
# define ststr stack<str>
//top()
# define dll deque<ll>
//at()
# define mll map<ll,ll>
#define mchar map<char, ll>
# define mstr map<str,ll>
# define mss map<str,str>
# define mci map<char,ll>
# define vp vector< pair<ll,ll> >
#define mp make_pair
#define ff first
#define ss second
#define pll pair<ll,ll>
# define f(x,y) for(int x=0;x<y;x++)
# define r(x,y) for(int x=y;x>=0;x--)
# define fr(x,y,z) for(int x=y;x<z;x++)
# define rr(x,y,z) for(int x=y;x>z;x--)
ll power(ll a , ll b){ll res=1;for(ll i=0; i<b; ++i){res*=a;}return res;}
ll logx(ll base, ll num){int cnt=0;while(num!=1){num/=base; ++cnt;}return cnt;}
ll gcd(ll a, ll b){
    if(b == 0)
        return a;
    return gcd(b, a % b);
}
ll lcm(ll a, ll b){
    return (a*b)/gcd(a, b);
}
void print(vll a){
    for(int i=0;i<a.size();i++){
        cout<<a[i]<<' ';
    }
    cout<<endl;
}
vll inp(int n){
    vll a;
    ll x;
    f(i,n){
        cin>>x;
        a.pb(x);
    }
    return a;
}
int main(){
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    int a[32] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
    ll k;
    cin>>k;
    cout<<a[k-1];
}