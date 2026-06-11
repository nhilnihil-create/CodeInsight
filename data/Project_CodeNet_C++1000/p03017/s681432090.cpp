#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;

int main(){
    int n,a,b,c,d; string s;
    cin>>n>>a>>b>>c>>d>>s;
    a--;b--;c--;d--;
    bool ng=false;
    if(c<b){
        for(int i=a; i<c-1; ++i){
            if(s[i]=='#'&&s[i+1]=='#')ng=true;
        }
        for(int i=b; i<d-1; ++i){
            if(s[i]=='#'&&s[i+1]=='#')ng=true;
        }
    }
    else if(c>=b&&c<d){
        for(int i=a; i<d-1; ++i){
            if(s[i]=='#'&&s[i+1]=='#')ng=true;
        }
    }
    else{
        bool ok=false;
        for(int i=b; i<=d; ++i){
            if(s[i-1]=='.'&&s[i]=='.'&&s[i+1]=='.')ok=true;
        }
        for(int i=a; i<c-1; ++i){
            if(s[i]=='#'&&s[i+1]=='#')ng=true;
        }
        if(!ok)ng=true;
    }
    cout<<(!ng?"Yes":"No")<<endl;
    return 0;
}
