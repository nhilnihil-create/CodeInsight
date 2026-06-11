#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define str to_string
#define endl "\n"
#define PI 3.141592653589
using namespace std;
using lint = long long;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}

vector<string> merge(int d,vector<string> &vec){
    if(d<=0)return vec;
    vector<string> nvec(0);
    for(string x:vec){
        set<char> s;
        for(char c:x){
            s.insert(c);
        }
        for(int i=0;i<=s.size();i++){
            nvec.pb(x+(char)('a'+i));
        }
    }
    vec=merge(d-1,nvec);
    return vec;
}

//AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC
int main(){
    int n;cin>>n;
    vector<string> vec={"a"};
    vec=merge(n-1,vec);
    for(auto x:vec)cout<<x<<endl;
}
