//#define _GLIBCXX_DEBUG
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
    string s;cin>>s;
    int n=s.size(),total=0,x=1;
    vector<int> vec(2019);vec[0]=1;
    lint ans=0;
    for(int i=n-1;i>=0;i--){
        total+=(s[i]-'0')*x;
        total%=2019;
        ans+=vec[total];
        vec[total]++;
        x=x*10%2019;
    }
    cout<<ans<<endl;
}
