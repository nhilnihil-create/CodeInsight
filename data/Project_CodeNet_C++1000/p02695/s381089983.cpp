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

int n,m,q,ans=0;
vector<int> a(0);
vector<int> b(0);
vector<int> c(0);
vector<int> d(0);
vector<int> suretu(11,0);

void dfs(int x){
    if(x>n){
        int tmp=0;
        for(int i=0;i<q;i++){
            if(suretu[b[i]]-suretu[a[i]]==c[i])tmp+=d[i];
        }
        ans=max(ans,tmp);
    }
    else{
        for(int i=suretu[x-1];i<=m;i++){
            suretu[x]=i;
            dfs(x+1);
        }
    }
}

//AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC
int main(){
    int A,B,C,D;
    cin>>n>>m>>q;
    for(int i=0;i<q;i++){
        cin>>A>>B>>C>>D;
        a.pb(A);b.pb(B);c.pb(C);d.pb(D);
    }
    suretu[0]=1;
    dfs(1);
    
    cout<<ans<<endl;
}
