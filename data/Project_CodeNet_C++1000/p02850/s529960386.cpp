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

int n;

void bfs(vector<vector<pair<int,int>>> &vec,vector<int> &ans,int color,int start){
    int e,v,c=0;
    vector<int> vc(n,-1);//それぞれの頂点をつっこむ時に使った色
    queue<pair<int,int>> q;
    for(auto p:vec[start]){
        q.push(p);
        ans[p.first]=c%color;
        vc[p.second]=c%color;
        c++;
    }
    while(!q.empty()){
        auto p=q.front();q.pop();
        e=p.first;v=p.second;
        c=vc[v]+1;
        for(auto np:vec[v]){
            if(ans[np.first]!=-1)continue;
            q.push(np);
            ans[np.first]=c%color;
            vc[np.second]=c%color;
            c++;
        }
    }
}

//AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC(*'ω'*)AC
int main(){
    int a,b;cin>>n;
    vector<int> edge(n);
    vector<int> ans(n,-1);
    vector<vector<pair<int,int>>> vec(n,vector<pair<int,int>>(0,pair<int,int>(0,0)));
    for(int i=0;i<n-1;i++){
        cin>>a>>b;
        vec[a-1].pb(make_pair(i,b-1));
        vec[b-1].pb(make_pair(i,a-1));
        edge[a-1]++;edge[b-1]++;
    }
    int highest=0,rem;
    for(int i=0;i<n;i++){
        if(highest<edge[i]){
            highest=edge[i];
            rem=i;
        }
    }
    bfs(vec,ans,highest,rem);
    cout<<highest<<endl;
    for(int i=0;i<n-1;i++){
        cout<<ans[i]+1<<endl;
    }
}
