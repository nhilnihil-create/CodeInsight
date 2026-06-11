#include<iostream>
#define _USE_MATH_DEFINES
#include<math.h>
#include<vector>
#include<array>
#include<algorithm>
#include<numeric>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<set>
#include<cstdio>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef vector<ll> vec;
typedef vector<vector<ll>> mat;
typedef pair<ll,ll> P;
typedef map<ll,ll> MP;
typedef priority_queue<ll> PQ;
typedef stack<ll> ST;
typedef queue<ll> QUE;
#define pb push_back
#define st first
#define nd second
#define SZ(x) ((int)(x).size())
#define FOR(i,s,n) for(int i=(int)(s); i< (int)(n); i++)
#define rep(i,n) FOR(i,0,n)
#define all(x) (x).begin(),(x).end()
#define each(x,c) for(auto x: (c))
#define LB(x,a) lower_bound(all(x), a)
#define UB(x,a) upper_bound(all(x), a)
const ll mod=1e9+7;
const ll INF=1e18;
const double EPS=1.0e-10;
const double PI=M_PI;

int main(){
    int N; cin>>N;
    string S; cin>>S;
    bool exist1=false;
    rep(i,N){
        if(S[i]=='2') exist1=true;
    }
    vec ord1(N),ord2(N),parity(N); ord1[0]=ord2[0]=0; parity[0]=1;
    FOR(i,1,N){
        ll x=i, y=N-i, res1=0, res2=0;
        while(x%2 == 0){
            x/=2;
            res1++;
        }
        while(y%2 == 0){
            y/=2;
            res2++;
        }
        ord1[i] = ord1[i-1]+res1;
        ord2[i] = ord2[i-1]+res2;
        if(ord2[i] == ord1[i]) parity[i]=1;
        else parity[i]=0;
    }
    if(exist1){
        ll res=0;
        rep(i,N){
            res += parity[i]*(S[i]-'1');
        }
        if(res%2 == 0) cout<<0<<endl;
        else           cout<<1<<endl;
        return 0;
    }
    else{
        ll res=0;
        rep(i,N){
            res += parity[i] * ((S[i]-'1')/2); 
        }
        if(res % 2 == 0) cout<<0<<endl;
        else             cout<<2<<endl;
        return 0;
    }
}