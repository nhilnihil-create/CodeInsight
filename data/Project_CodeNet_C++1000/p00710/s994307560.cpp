#include <bits/stdc++.h>
#define PB push_back
#define MP make_pair
#define REP(i,n) for (int i=0;i<(n);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
#define ALL(a) (a).begin(),(a).end()
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<string,string> P;
const int INF=1e9+1;
int dat[50];
int n;
void rec(int p,int c){
      int tmp[50];
      REP(i,n)tmp[i]=dat[i];
      for(int i=0;i<c;i++)tmp[i]=dat[i+p-1];
      for(int i=c;i<c+p-1;i++)tmp[i]=dat[i-c];
      REP(i,n)dat[i]=tmp[i];
}
int main(){
      int r;
      while(cin>>n>>r&&(n||r)){
            REP(i,n)dat[i]=n-i;
            REP(i,r){
                  int a,b;
                  cin>>a>>b;
                  rec(a,b);
            }
            cout<<dat[0]<<endl;
      }
}