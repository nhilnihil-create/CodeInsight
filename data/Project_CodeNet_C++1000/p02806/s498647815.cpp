#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define pb push_back
#define all(v) v.begin(),v.end()
#define fi first
#define se second
#define bigger (char)toupper
#define smaller (char)tolower
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<vi> vii;
typedef vector<string> vs;
typedef vector<char> vc;
typedef long long ll;
typedef unsigned long long ull;

int main() {
    int N;
    cin>>N;
    vector<pair<string,int>> st(N);
    rep(i,N) {
        string s;
        int t;
        cin>>s>>t;
        st[i]=make_pair(s,t);
    }
    string X;
    cin>>X;
    int total=0;
    rep(i,N) {
        total+=st[i].se;
    }
    int wake=0;
    int point;
    rep(i,N) {
        if(st[i].fi==X) {
            point=i;
            break;
        }
        wake+=st[i].se;
    }
    wake+=st[point].se;
    int answer=total-wake;
    cout<<answer<<endl;
}