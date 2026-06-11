//#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ld long double
#define al(a) (a).begin(),(a).end()
#define mk make_pair
#define check cout<<"?"<<endl;

ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=1e18+5;

int main(){
    int n; cin>>n;
    int a,b,c,d; cin>>a>>b>>c>>d;
    a--; b--; c--; d--;
    string s,ans="Yes"; cin>>s;
    if(c<d){
        for(int i=b+1;i<d-1;i++){
            if(s[i]=='#' && s[i+1]=='#') ans="No";
        }
        for(int i=a+1;i<c-1;i++){
            if(s[i]=='#' && s[i+1]=='#') ans="No";
        }
        cout<<ans<<endl;
    }
    else{
        ans="No";
        for(int i=b;i<=d;i++){
            if(s[i-1]=='.' && s[i]=='.' && s[i+1]=='.') ans="Yes";
        }
        if(ans=="No") cout<<ans<<endl;
        else{
            for(int i=a+1;i<c-1;i++){
                if(s[i]=='#' && s[i+1]=='#') ans="No";
            }
            cout<<ans<<endl;
        }
    }
}

