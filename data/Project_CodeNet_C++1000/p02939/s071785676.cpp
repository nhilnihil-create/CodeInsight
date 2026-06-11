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
    string s;char rem;cin>>s;int ans=0;bool skip=false;
    for(int i=0;i<s.size();i++){
        if(skip){rem='A';ans++;skip=false;continue;}
        if(i==0){rem=s[0];ans++;}
        else{
            if(rem==s[i]){
                skip=true;
            }
            else{
                rem=s[i];ans++;
            }
        }
    }
    cout<<ans<<endl;
}
