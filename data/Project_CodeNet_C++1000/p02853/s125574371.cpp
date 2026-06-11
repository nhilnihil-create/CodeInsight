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
    int x,y,ans=0;cin>>x>>y;
    if(x==1)ans+=300000;
    if(y==1)ans+=300000;
    if(x==2)ans+=200000;
    if(y==2)ans+=200000;
    if(x==3)ans+=100000;
    if(y==3)ans+=100000;
    if(x==1&&y==1)ans+=400000;
    cout<<ans<<endl;
}
