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

vector<pair<int,int>> way={{1,0},{0,1}};
//(*'ω'*)ACほちぃ...
int main(){
    int h,w,r,c,nr,nc;cin>>h>>w;
    vector<string> maze(h);
    for(int i=0;i<h;i++)cin>>maze[i];
    vector<vector<int>> change(h,vector<int>(w,1000));
    vector<vector<int>> visited(h,vector<int>(w,0));
    change[0][0]=0;
    queue<pair<int,int>> q;
    q.push(make_pair(0,0));
    while(!q.empty()){
        auto p=q.front();q.pop();
        r=p.first;c=p.second;
        for(auto wp:way){
            nr=r+wp.first;nc=c+wp.second;
            if(nr>h-1||nc>w-1)continue;
            if(maze[nr][nc]==maze[r][c]){
                change[nr][nc]=min(change[nr][nc],change[r][c]);
            }
            else{
                change[nr][nc]=min(change[nr][nc],change[r][c]+1);
            }
            if(!visited[nr][nc]){
                q.push(make_pair(nr,nc));
                visited[nr][nc]=1;
            }
        }
    }
    int tmp=change[h-1][w-1];
    int ans=(tmp+1)/2;
    if(maze[0][0]=='#'&&maze[h-1][w-1]=='#')ans++;
    cout<<ans<<endl;
}
