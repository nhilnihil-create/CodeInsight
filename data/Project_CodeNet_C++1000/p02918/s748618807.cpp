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
    int n,k,h=0;cin>>n>>k;
    string s;cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='R'){
            if(i==n-1)continue;
            else if(s[i+1]=='R')h++;
        }
        else{
            if(i==0)continue;
            else if(s[i-1]=='L')h++;
        }
    }
    cout<<min(n-1,h+k*2)<<endl;
}
