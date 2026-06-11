#include <bits/stdc++.h>
#define all(v) v.begin(), v.end()
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define con_input(v) for(auto it=v.begin();it!=v.end();it++){cin>>*it;}
#define con_debug(v) for(auto it=v.begin();it!=v.end();it++){cerr<<*it<<" ";}cerr<<endl;
using namespace std;
struct point{int x;int y;};
int i,j,k,count1=0,count2=0;

int main(){
    vector<int> list={0,300000,200000,100000};
    int x,y,ans=0;
    cin>>x>>y;
    if(x<=3)ans+=list[x];
    if(y<=3)ans+=list[y];
    if(x==1&&y==1)ans+=400000;
    cout<<ans<<endl;
}
