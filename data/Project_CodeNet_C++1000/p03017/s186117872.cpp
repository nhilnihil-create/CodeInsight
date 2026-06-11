#include <bits/stdc++.h>
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll=long long;
int main(){
    int n,a,b,c,d; string s;
    cin>>n>>a>>b>>c>>d>>s;
    s='.'+s;
    if(c<d){
        for(int i=a; i<=d-2; ++i){
            if(s[i]=='#'&&s[i+1]=='#'){
                cout<<"No"<<endl;
                return 0;
            }
        }
        cout<<"Yes"<<endl;
    }
    else{
        for(int i=a; i<=c-2; ++i){
            if(s[i]=='#'&&s[i+1]=='#'){
                cout<<"No"<<endl;
                return 0;
            }
        }
        bool ok=false;
        for(int i=b-1; i<=d-1; ++i){
            if(s[i]=='.'&&s[i+1]=='.'&&s[i+2]=='.')ok=true;
        }
        cout<<(ok==true?"Yes":"No")<<endl;
    }
}