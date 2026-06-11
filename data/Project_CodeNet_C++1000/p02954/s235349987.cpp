#include<bits/stdc++.h>
using namespace std;
#define ALL(v) (v).begin(),(v).end()
#define REP(i,p,n) for(int i=p;i<(int)(n);++i)
#define rep(i,n) REP(i,0,n)
#define SZ(x) ((int)(x).size())
#define debug(x) cerr << #x << ": " << x << '\n'
const char newl = '\n';
typedef long long int Int;
typedef pair<int,int> P;
using ll = long long;
using VI = vector<int>;
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const long long INF = 1LL<<60;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    vector<int> vec(n,0);
    vector<int> ans(n,0);
    int t = 0;
    for(int i=n-1;i>=0;i--){
        if(s[i]=='R') t++;
        else t = 0;
        vec[i] += t;
    }
    for(int i=0;i<n;i++){
        if(s[i] == 'L') t++;
        else t = 0;
        vec[i] += t;
    }   
    /*for(auto &i:vec){
        cout << i << " ";
    }
    cout << endl;*/  
    rep(i,n){
        int v=0;
        if(s[i]=='R'){
            if(vec[i]&1){
                v = -1;
            }else{
                v = 0;
            }
            v = i+v+vec[i];
            ans[v]++;
        }else{
            if(vec[i]&1){
                v = -1;
            }else{
                v = 0;
            }
            v = v+vec[i];
            ans[i-v]++;
        }
    }
    /*for(auto &i:vec){
        cout << i << " ";
    }
    cout << endl;*/
    for(auto &i:ans){
        cout << i << " ";
    }
    cout << endl;
}