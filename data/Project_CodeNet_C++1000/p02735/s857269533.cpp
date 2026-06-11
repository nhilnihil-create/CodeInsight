#include <bits/stdc++.h>

using namespace std;
#define all(a)a.begin(),a.end()
using ll=long long;
const int INF = 1<<30;
const ll INFll =1LL<<62;
const int mod= int(1e9)+7;
using P = pair<ll,ll>;
using ld=long double;

int main(){
    int h,w;cin >>h>>w;
    vector<string>s(h);
    for (int i = 0; i < h; ++i) {
        cin >>s[i];
    }
    queue<P>que;
    que.push({0,0});
    vector<vector<int>>d(h,vector<int>(w,INF));
    d[0][0]=(s[0][0]=='#')?1:0;
    while(!que.empty()){
        P pos=que.front();que.pop();
        int x=pos.second;
        int y=pos.first;
        int now=d[y][x];
        char key=s[y][x];
        if(x+1<w){
            int cost=(s[y][x+1]!=key)?1:0;
            if(d[y][x+1]>now+cost){
                d[y][x+1]=now+cost;
                que.push({y,x+1});
            }
        }
        if(y+1<h){
            int cost=(s[y+1][x]!=key)?1:0;
            if(d[y+1][x]>now+cost){
                d[y+1][x]=now+cost;
                que.push({y+1,x});
            }
        }
    }
    if(s[h-1][w-1]=='#')d[h-1][w-1]++;
    cout <<d[h-1][w-1]/2<<endl;
}
