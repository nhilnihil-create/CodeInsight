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
    int m,d,a,b,ans=0;cin>>m>>d;
    string s;
    for(int i=4;i<=m;i++){
        for(int j=22;j<=d;j++){
            s=str(j);
            a=s[0]-'0';
            b=s[1]-'0';
            if(a>1&&b>1&&a*b==i)ans++;
        }
    }
    cout<<ans<<endl;
}
