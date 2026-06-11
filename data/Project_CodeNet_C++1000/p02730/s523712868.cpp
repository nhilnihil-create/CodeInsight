#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef unsigned long long int ulli;
#define vec(s) vector<s>
#define vvec(s) vector<vector<s>>
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef pair<lli,lli> pii;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define YN(x) cout<<(x?"Yes":"No")<<endl;
#define out(s) cout<<s<<endl;
#define pb(s) push_back(s);
#define sp " ";
#define INF 10000000000
#define LINF 9000000000000000000
#define all(s) s.begin(),s.end()
void vout(vi v){
    for(int i=0;i<v.size();i++)
    cout<<v.at(i)<<endl;
}
int main(){
    bool c1 = false,c2=false,c3=false;
    string s,sr;
    cin >> s;
    lli n = s.size();
    sr = s;
    reverse(all(sr));
    if(s==sr){
        c1 = true;
    }
    string ss1, ssr1;
    ss1 = s.substr(0,(n-1)/2);
    ssr1 = ss1;
    reverse(all(ssr1));
    if(ssr1==ss1){
        c2 = true;
    }
    string ss2, ssr2;
    ss2 = sr.substr(0, (n - 1) / 2);
    ssr2 = ss2;
    reverse(all(ssr2));
    if(ssr2==ss2){
        c3 = true;
    }
    YN(c1 && c2 && c3);
}