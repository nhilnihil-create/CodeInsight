#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
const ll INF=1LL<<60;
const double EPS = 1e-10;
const ll mod=1000000007;

int main(void){
    int n,a,b,c,d;
    string s;
    cin>>n>>a>>b>>c>>d>>s;
    a--,b--,c--,d--;
    bool ans=true;
    for(int i=a;i<c;i++){
        if(s[i]=='#'&&s[i+1]=='#') ans=false;
    }
    for(int i=b;i<d;i++){
        if(s[i]=='#'&&s[i+1]=='#') ans=false;
    }
    if(c>d){
        bool kari=false;
        for(int i=b-1;i<d;i++){
            if(s[i]=='.'&&s[i+1]=='.'&&s[i+2]=='.') kari=true;
        }
        if(kari==false) ans=false;
    }
    if(ans) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
