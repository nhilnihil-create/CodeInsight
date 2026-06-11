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
    int a,b,m,x,y,c;cin>>a>>b>>m;
    vector<int> A(a);for(int i=0;i<a;i++)cin>>A[i];
    vector<int> B(b);for(int i=0;i<b;i++)cin>>B[i];
    int ans=*min_element(all(A))+*min_element(all(B));
    for(int i=0;i<m;i++){
        cin>>x>>y>>c;
        ans=min(ans,(A[x-1]+B[y-1]-c));
    }
    cout<<ans<<endl;
}
