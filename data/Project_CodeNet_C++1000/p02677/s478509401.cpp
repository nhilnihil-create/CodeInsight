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
    double a,b,h,m,d,ans;cin>>a>>b>>h>>m;
    m=360*m/60;
    h=360*h/12+m/12;
    d=min(abs(m-h),360-abs(m-h));
    ans=sqrt(a*a+b*b-2*a*b*cos(d*PI/180));
    cout<<fixed<<setprecision(15)<<ans<<endl;
}
