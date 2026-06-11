#include<iostream>
#include<iomanip>
#include<map>
#include<set>
#include<string>
#include<algorithm>
#include<cmath>
#include<vector>
#include<queue>
#include<stack>
 
using namespace std;
 
#define P(p) cout<<(p)<<endl
#define rep(i,m,n) for(int i = (m); i < (int)(n); i++)
#define rrep(i,m,n) for(int i=(int)(m); i>=(int)(n); i--)
#define vsort(v) sort(v.begin(), v.end());
#define rvsort(v) sort(v.begin(), v.end(),greater<int>());
#define YES cout<<"YES"<< endl
#define NO cout<<"NO"<<endl
#define Yes cout<<"Yes"<<endl
#define No cout<<"No"<<endl  
#define yes cout<<"yes"<<endl
#define no cout<<"no"<<endl
#define ret return
#define C(i) cin>>i
#define C2(i,j) cin>>i>>j
#define C3(i,j,k) cin>>i>>j>>k
#define C4(i,j,k,m) cin>>i>>j>>k>>m
////////////////////////////////////////////////////////////

struct S{
  int num;
  int x;
  int y;
};

int main(){
  int h,w,n;
  C3(h,w,n);
  
  int f[h][w] = {};
  pair<int,int> g[n+1];
  pair<int,int> s[n+1];
  rep(i,0,h){
    rep(j,0,w){
      char c;
      cin >> c;
      if(c == 'X'){
        f[i][j] = -1;
      }
      else if(c == '.'){
        f[i][j] = 0;
      }
      else if(c == 'S'){
        pair<int,int> tt = {j,i};
        s[1] = tt;
      }
      else{
        int t = c - '0';
        f[i][j] = t;
        pair<int,int> tt = {j,i};
        g[t] = tt;
        
        if(t < n){
          s[t+1] = tt;
        }

      }
    }
  }

  int ans = 0;
  rep(i,1,n+1){
    int sx = s[i].first;
    int sy = s[i].second;
    int gx = g[i].first;
    int gy = g[i].second;
    //printf("sx:%d sy:%d gx:%d gy:%d\n",sx,sy,gx,gy);
    queue<struct S> q;
    struct S tmp = {0,sx,sy};
    q.push(tmp);
    
    int fNum[h][w];
    rep(i,0,h)
      rep(j,0,w)
      fNum[i][j] = 0xFFFFFFF;
    

    while(!q.empty()){
      struct S s = q.front();
      //printf("i:%d n:%d x:%d y:%d\n",i,s.num,s.x,s.y);
      q.pop();
      if(f[s.y][s.x] == -1){
        continue;
      }
      if(s.num >= fNum[s.y][s.x] && s.num != 0)
        continue;

      fNum[s.y][s.x] = s.num;
      if(s.y == gy && s.x == gx)
        continue;

      else{
        if(s.y > 0){
          if(f[s.y-1][s.x] != -1&& fNum[s.y-1][s.x] > s.num+1){
            struct S t = {s.num+1,s.x,s.y-1};
            q.push(t);
          }
        }
        if(s.x + 1 <= w - 1 ){
          if(f[s.y][s.x+1] != -1 && fNum[s.y][s.x+1] > s.num+1){
            struct S r = {s.num+1,s.x+1,s.y};
            q.push(r);
          }
        }
        if(s.x > 0){
          if(f[s.y][s.x-1] != -1 && fNum[s.y][s.x-1] > s.num+1){
            struct S l = {s.num+1,s.x-1,s.y};
            q.push(l);
          }
        }
        if(s.y + 1 <= h -1 ){
          if(f[s.y+1][s.x] != -1 && fNum[s.y+1][s.x] > s.num+1){
            struct S b = {s.num+1,s.x,s.y+1};     
            q.push(b);
          }
        }
      }
    }

    ans += fNum[gy][gx];
  }

  P(ans);

  ret 0;
}