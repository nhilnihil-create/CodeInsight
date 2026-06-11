#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0; i < (ll)(n); i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll INF = 1LL << 60;
int main(){
    int n,a,b,c,d;
    cin >> n >> a >> b >> c >> d;
    a--; b--; c--; d--;
    string s;
    cin >> s;
    if(a>b) {
        swap(a,b);
        swap(c,d);
    } //aは常にbより小さい
    if(c<a||d<b){
        cout << "No" << endl;
        return 0;
    }
    for(int i=a+1; i<c; i++){
        if(s[i]=='#'&&s[i+1]=='#'){
            cout << "No" << endl;
            return 0;
        }
    }
    for(int i=b+1; i<d; i++){
        if(s[i]=='#'&&s[i+1]=='#'){
            cout << "No" << endl;
            return 0;
        }
    }
    if(c<d){
        cout << "Yes" << endl;
        return 0;
    }
    if(c>d){
        int fi = max(b-1,a);
        int la = min(d-1,c-2);
        for(int i=fi; i<=la; i++){
            if(s[i]=='.'&&s[i+1]=='.'&&s[i+2]=='.'){
                cout << "Yes" << endl;
                return 0;
            }
        }
        cout << "No" << endl;
        return 0;
    }
    return 0;
}