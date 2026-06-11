#include<bits/stdc++.h>
#define X first
#define Y second
#define pb push_back
#define eb emplace_back


#define rep(X,Y) for(int (X) = 0; (X) < (Y) ; ++(X))
#define all(X) (X).begin,(X).end
#define reps(i,j,k) for(inti=(j); i <= (k); ++(i))
#define sz size()
#define in(i,j,k) ((i) >= (j) && (i) <= (k))

using namespace std;
typedef pair<int,int> pii;

int dx[]={-1,0,1,0},dy[]={0,1,0,-1};

int main(){
  int n;
  while(cin>>n,n){
    vector<pii> pos;
    pos.eb(0,0);
    rep(i,n-1){
      int a,d;
      cin>>a>>d;
      pos.eb(pos[a].X+dx[d], pos[a].Y+dy[d]);
    }
    int x=0,X=0,y=0,Y=0;
    rep(i,n){
      x=min(x,pos[i].X); X=max(X,pos[i].X);
      y=min(y,pos[i].Y); Y=max(Y,pos[i].Y);
    }
    cout<<X-x+1<<" "<<Y-y+1<<endl;
  }
    return 0;
}