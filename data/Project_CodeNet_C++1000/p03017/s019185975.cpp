#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i<n;i++)
#include <bits/stdc++.h>
#include <numeric>
using namespace std;
typedef long long ll;
const int mod= 1e+9+7;

int main() {
    int N,A,B,C,D; cin>>N>>A>>B>>C>>D;
    vector<char>s(N);
    rep(i,N)cin>>s[i];
    bool judge =true;
    if(C<D){
        for(int i=A;i<D-2;i++){
            if(s[i]=='#'&&s[i+1]=='#'){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    else {
        for(int i=B;i<D+1;i++){
            if(s[i-2]=='.'&&s[i-1]=='.'&&s[i]=='.')judge=false;
        }
        if(judge){
            cout<<"No"<<endl;
            return 0;
        }
        for(int i=A;i<C-2;i++){
            if(s[i]=='#'&&s[i+1]=='#'){
                cout<<"No"<<endl;
                return 0;
            }
        }
    }
    cout<<"Yes"<<endl;
}