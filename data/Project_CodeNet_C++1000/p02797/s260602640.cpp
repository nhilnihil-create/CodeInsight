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
    int n,k,s;cin>>n>>k>>s;
    if(k==n){
        for(int i=0;i<n;i++){
            if(i==n-1)cout<<s<<endl;
            else cout<<s<<" ";
        }return 0;
    }
    if(s==1){
        for(int i=0;i<k;i++){
            cout<<1<<" ";
        }
        for(int i=k;i<n;i++){
            cout<<10;
            if(i==n-1)cout<<endl;
            else cout<<" ";
        }return 0;
    }
    int age=(s+1)/2;
    int sage=s/2;
    for(int i=0;i<=k;i++){
        if(i%2==0)cout<<age;
        else cout<<sage;
        if(i==n-1)cout<<endl;
        else cout<<" ";
    }
    for(int i=0;i<n-(k+1);i++){
        if(s==1000000000)cout<<999999999;
        else cout<<1000000000;
        if(i==n-(k+1)-1)cout<<endl;
        else cout<<" ";
    }
}
