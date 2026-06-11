// ABC146-D
#include <bits/stdc++.h>
#define endl "\n"
#define rep(i,n) for(int i=0;i<int(n);i++)
#define SZ(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
using namespace std;
typedef long long ll;
template <class T>ostream &operator<<(ostream &o,const vector<T>&v)
{o<<"{";for(int i=0;i<(int)v.size();i++)o<<(i>0?", ":"")<<v[i];o<<"}";return o;}
namespace you {
    std::string to_string(char val) {
        return std::string(1, val);
        // return std::string{val};
        // you::to_string(char)
    }
}

int num=pow(10,5)+2;
vector<vector<int>> node(num+1);
vector<vector<int>> hen(num+1);
vector<int> col(num);
vector<int> seen(num+1);
vector<int> setu(num+1,0);

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(12);

    int n;
    cin>>n;
    struct local{
        static void dfs(int x,int c){
            seen[x]=1;
            int color=1;
            //int kaburi=0;
            for(int i=0;i<setu[x];i++){
                if(seen[node[x][i]]==1){
                    continue;
                }
                if(color==c) color+=1;
                col[hen[x][i]]=color;
                dfs(node[x][i],color);
                color+=1;
            }
        }
    };
    rep(i,n-1){
        int a,b;
        cin>>a>>b;
        node[a].push_back(b);
        node[b].push_back(a);
        hen[a].push_back(i);
        hen[b].push_back(i);
        setu[a]+=1;
        setu[b]+=1;
    }
    //cout<<node<<endl;
    int max_=0;
    rep(i,n+1){
        if(max_<setu[i]) max_=setu[i];
    }
    //cout<<max_<<endl;
    local::dfs(1,0);
    cout<<max_<<endl;
    for(int i=0;i<n-1;i++){
        cout<<col[i]<<endl;
        //cout<<node[i]<<endl;
    }
    return 0;
}