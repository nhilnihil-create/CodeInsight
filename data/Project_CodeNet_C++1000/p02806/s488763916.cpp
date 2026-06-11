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
    int n,ans=0;cin>>n;
    vector<string> s(n);
    vector<int> t(n);
    for(int i=0;i<n;i++)cin>>s[i]>>t[i];
    string st;cin>>st;
    bool sleep=false;
    for(int i=0;i<n;i++){
        if(!sleep){
            if(s[i]==st)sleep=true;
        }
        else{
            ans+=t[i];
        }
    }
    cout<<ans<<endl;
}
