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

//AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC
int main(){
    int n,a,b,c,d,x;cin>>n>>a>>b>>c>>d;
    a--;b--;c--;d--;x=max(c,d);
    string s,ans="Yes";cin>>s;
    for(int i=a;i<x;i++){
        if(s[i]=='#'&&s[i+1]=='#'){cout<<"No"<<endl;return 0;}
    }
    if(c>d){
        bool ev=false;
        for(int i=b;i<=d;i++){
            if(s[i-1]==s[i]&&s[i]==s[i+1]&&s[i]=='.'){ev=true;break;}
        }
        if(!ev)ans="No";
    }
    cout<<ans<<endl;
}
