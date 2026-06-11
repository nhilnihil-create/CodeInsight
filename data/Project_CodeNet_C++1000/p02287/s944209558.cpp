#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define loop(i,x,n) for(int i=x;i<n;i++)
#define pb push_back
#define int long long
#define MAX 100005
#define NIL -1
using namespace std;
const int MOD=1000000007;
const int INF=1000000009;
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int parent(int i){return i/2;}
int left(int i){return i*2;}
int right(int i){return i*2+1;}

signed main(){
  int h,A[MAX+1];
  cin>>h;
  loop(i,1,h+1)cin>>A[i];
  loop(i,1,h+1){
    cout<<"node "<<i<<": key = "<<A[i]<<", ";
    if(parent(i)>=1)cout<<"parent key = "<<A[parent(i)]<<", ";
    if(left(i)<=h)cout<<"left key = "<<A[left(i)]<<", ";
    if(right(i)<=h)cout<<"right key = "<<A[right(i)]<<", ";
    cout<<endl;
  }

  return 0;
}