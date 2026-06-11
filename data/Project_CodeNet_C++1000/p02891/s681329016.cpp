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
    string s;cin>>s;
    lint k,ans=0;cin>>k;
    int sz=s.size();
    vector<int> vec(0);
    char rem=s[0];int tmp=1;
    for(int i=1;i<sz;i++){
        if(s[i]!=rem){
            vec.pb(tmp);
            rem=s[i];tmp=1;
        }
        else tmp++;
    }
    vec.pb(tmp);
    if(tmp==sz)ans=(sz*k)/2;
    else{
        if(s[0]!=s[sz-1]){
            for(int x:vec){
                ans+=x/2;
            }
            ans*=k;
        }
        else{
            int front=vec[0];
            int v=vec.size();
            int back=vec[v-1];
            ans+=(front/2)+(back/2);
            ans+=(front+back)/2*(k-1);
            lint tmp2=0;
            for(int i=1;i<v-1;i++){
                tmp2+=vec[i]/2;
            }
            ans+=tmp2*k;
        }
    }
    cout<<ans<<endl;
}