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
    vector<pair<double,double>> vec1(n,pair<double,double>(0.0,0.0)),vec2(n,pair<double,double>(0.0,0.0));
    for(int i=0;i<n;i++)cin>>vec1[i].first>>vec1[i].second;
    for(int i=0;i<n;i++){
        vec2[i].first=vec1[i].second;
        vec2[i].second=vec1[i].first;
    }
    sort(all(vec1));sort(all(vec2));
    if(n%2==1){
        int x=(n+1)/2;
        double smallest=vec1[x-1].first;
        double largest=vec2[x-1].first;
        cout<<int(largest-smallest)+1<<endl;
    }
    else{
        int x1=n/2,x2=n/2+1;
        double smallest=(vec1[x1-1].first+vec1[x2-1].first)/2;
        double largest=(vec2[x1-1].first+vec2[x2-1].first)/2;
        int ans=(largest-smallest)/0.5+1;
        cout<<ans<<endl;
    }
}
