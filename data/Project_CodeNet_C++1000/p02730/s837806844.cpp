#include<bits/stdc++.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define RREP(i,n) for(int i=n;i>=0;i--)
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define ALL(v) v.begin(), v.end()
#define RALL(v) v.rbegin(), v.rend()
using namespace std;
typedef long long ll;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
//const ll INF = 1LL << 60;
//const int INF = 1001001001;

int main(void){
    string s;
    cin >> s;
    string t=s;
    reverse(ALL(t));
    if(t!=s){
        cout << "No";
        return 0;
    }
    int n=(s.size()-1)/2;
    string s1=s.substr(0,n);
    string t1=s1;
    reverse(ALL(t1));
    if(t1!=s1){
        cout << "No";
        return 0;
    }

    string s2=s.substr((s.size()+3)/2-1,n);
    string t2=s2;
    reverse(ALL(t2));
    if(t2!=s2){
        cout << "No";
        return 0;
    }
    cout << "Yes";
    return 0;
}