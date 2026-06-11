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
    lint x,y,x1,x2,y1,y2;
    vector<pair<lint,lint>> vec(n,pair<lint,lint>(0,0));
    for(int i=0;i<n;i++)cin>>vec[i].first>>vec[i].second;
    map<pair<lint,lint>,int> dic;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j)continue;
            x1=vec[i].first;
            y1=vec[i].second;
            x2=vec[j].first;
            y2=vec[j].second;
            x=x2-x1;y=y2-y1;
            dic[make_pair(x,y)]++;
        }
    }
    int freq=0;
    for(auto p:dic){
        if(p.second>freq){
            x=p.first.first;
            y=p.first.second;
            freq=p.second;
        }
    }
    lint tx,ty;
    int ans=n;
    for(int i=0;i<n;i++){
        tx=vec[i].first+x;ty=vec[i].second+y;
        for(int j=0;j<n;j++){
            if(tx==vec[j].first && ty==vec[j].second)ans--;
        }
    }
    cout<<ans<<endl;
}
