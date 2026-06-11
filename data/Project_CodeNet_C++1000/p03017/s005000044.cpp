#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<(n);i++)
#define rrep(i,n) for(ll i=(n)-1;i>=0;i--)
template<typename T =ll> using v = vector<T>;
template<typename T =ll> using vv = v<v<T>>;
template<typename T=ll,typename U=ll> using p = pair<T,U>;
template<typename T> T chmin(T &a,T b) {return a=min(a,b);}
template<typename T> T chmax(T &a,T b) {return a=max(a,b);}
const ll INF = (ll)1e9;


int main(){
    int n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    string s;  cin >> s;
    s="#"+s+"#";
 
    auto search = [&s](int st,int en){
        for(int i=st;i<en;i++){
            if(s[i]=='#'&&s[i+1]=='#') return false;
        }
        return true;
    };

    if(!search(a,c)||!search(b,d)){
        cout << "No"<<endl;
        return 0;
    }
    

    if(c>d){
        for(int i=b;i<=d;i++){
            if(s[i-1]=='.'&&s[i]=='.'&&s[i+1]=='.'){
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No"<<endl;
        return 0;
    }

    cout << "Yes"<<endl;    

    return 0;
}