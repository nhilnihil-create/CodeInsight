#define _LIBCPP_DEBUG 0
#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef vector<int> vi;
typedef long long ll;



int main(){
    
    ll N,A,B,C,D;cin>>N>>A>>B>>C>>D;
    string s;cin>>s;
    int pc=0,sc=0,pok=0,sng=0;
    rep(i,A,C-1){
        
        if(s.at(i)=='#'&&s.at(i+1)=='#'){
            cout<<"No"<<endl;
            return 0;
        }
    
    }
    rep(i,B,D-1){
        
        if(s.at(i)=='#'&&s.at(i+1)=='#'){
            cout<<"No"<<endl;
            return 0;
        }
    
    }
    if(C>D){
        rep(i,B-1,D){
            if(pok==1)break;
            if(s.at(i-1)=='.'&&s.at(i)=='.'&&s.at(i+1)=='.')pok=1;
        }
        if(pok==0){
            cout<<"No"<<endl;
            return 0;
        }
    }
    cout<<"Yes"<<endl;

}




