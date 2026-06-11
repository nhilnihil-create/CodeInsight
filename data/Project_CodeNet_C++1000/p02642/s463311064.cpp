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

//(*'ω'*)ACほちぃ...
int main(){
    int n;cin>>n;
    vector<int> a(n);
    for(int i=0;i<n;i++)cin>>a[i];
    sort(all(a));
    vector<int> done(1000001);
    vector<int> check(1000001);
    for(int i=0;i<n;i++){
        int x=a[i];
        if(done[x]){
            check[x]=1;continue;
        }
        for(int j=x;j<=1000000;j+=x){
            done[j]=1;
            if(j!=x)check[j]=1;
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        if(check[a[i]]==0)ans++;
    }
    cout<<ans<<endl;
}