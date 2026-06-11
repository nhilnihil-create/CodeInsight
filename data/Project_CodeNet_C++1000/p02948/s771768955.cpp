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
    int n,m,a,b,ans=0;cin>>n>>m;
    vector<pair<int,int>> vec(n,pair<int,int>(0,0));
    for(int i=0;i<n;i++){
        cin>>a>>b;
        vec[i]=make_pair(a,b);
    }
    sort(all(vec));
    priority_queue<int> pq;
    bool allok=false;
    int pnt=0;
    for(int i=1;i<=m;i++){
        if(!allok){
            while(vec[pnt].first<=i){
                pq.push(vec[pnt].second);
                pnt++;
                if(pnt>=n){
                    allok=true;break;
                }
            }
        }
        if(!pq.empty()){
            ans+=pq.top();pq.pop();
        }
    }
    cout<<ans<<endl;
}
