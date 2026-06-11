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
    lint a,b,c;cin>>a>>b>>c;
    bool ans;
    lint tmp=a+b-c;
    if(tmp>=0)ans=false;
    else{
        if(tmp*tmp>4*a*b)ans=true;
        else ans=false;
    }
    if(ans)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
}
