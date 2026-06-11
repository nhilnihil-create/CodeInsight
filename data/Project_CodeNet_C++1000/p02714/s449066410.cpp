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
    ll n,g=0,b=0,r=0,x=0;
    string s;
    cin>>n>>s;
    REP(i,n){
        if(s[i]-'R'==0)g++;
        else if(s[i]-'G'==0)b++;
        else r++;
    }
    int i=1;
    while(i*2<n){
        for(int j=0;j+i*2<n;j++){
            if(s[j]-s[j+i]!=0&&s[j+i]-s[j+i*2]!=0&&s[j]-s[j+i*2]!=0)x++;
        }
        i++;
    }
    cout<<g*b*r-x<<endl;
}