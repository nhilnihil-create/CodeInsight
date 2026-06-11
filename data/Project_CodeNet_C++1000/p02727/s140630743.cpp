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
    int x,y,a,b,c;cin>>x>>y>>a>>b>>c;
    vector<lint> p(a);for(int i=0;i<a;i++)cin>>p[i];
    vector<lint> q(b);for(int i=0;i<b;i++)cin>>q[i];
    vector<lint> r(c);for(int i=0;i<c;i++)cin>>r[i];
    sort(all(p),greater<lint>());sort(all(q),greater<lint>());sort(all(r),greater<lint>());
    int pa=0,pb=0,pc=0,ba=x-1,bb=y-1;
    lint ans=0;bool aend=false,bend=false;
    for(int rep=0;rep<x+y;rep++){
        if(p[pa]>=q[pb]&&p[pa]>=r[pc]){
            ans+=p[pa];
            pa++;
            if(pa>ba){pa=0;p[0]=0;aend=true;}
        }
        else if(q[pb]>=r[pc]){
            ans+=q[pb];
            pb++;
            if(pb>bb){pb=0;q[0]=0;bend=true;}
        }
        else{
            ans+=r[pc];
            if(p[ba]<q[bb]||bend){
                ba--;
                if(pa>ba){pa=0;ba=0;p[0]=0;aend=true;}
            }
            else{
                bb--;
                if(pb>bb){pb=0;bb=0;q[0]=0;bend=true;}
            }
            pc++;
            if(pc>=c){pc=0;r[0]=0;}
        }
    }
    cout<<ans<<endl;
}
