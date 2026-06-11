#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for (int i=(a);i<(b);++i)
#define REP(i,n) for (int i=0;i<(n);++i)
#define all(a) (a).begin(),(a).end()
#define MOD 1000000007
using ll = long long;
using P = pair<int, int>;
using vi = vector<int>;
using vl = vector<ll>;
using vs = vector<string>;
using vc = vector<char>;
using vb = vector<bool>;
const int INFTY =2147483647;
int main(){
    ll n,p,b,c;
    string ans="";
    cin>>n;
    n--;
    while(n>25){
        b=n/26;
        c=n%26;
        ans=(char)(c+97)+ans;
        n=b-1;
    }
    ans=(char)(n+97)+ans;
    cout<<ans<<endl;
}