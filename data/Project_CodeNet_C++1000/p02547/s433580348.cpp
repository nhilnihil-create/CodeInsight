#include<bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define mod 1000000007
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define REP(i,a,b) for(int i=a;i<b;i++)
#define maxx 1000001
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

int main(){
    FASTIO
    int n;
    cin>>n;
    int d[2][n];
    REP(i,0,n)
      cin>>d[0][i]>>d[1][i];
    bool ok=false;
    REP(i,0,n-2){
      if(d[0][i]==d[1][i]&&d[0][i+1]==d[1][i+1]&&d[0][i+2]==d[1][i+2]){
        ok=true;break;
      }
    }
    if(ok) cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}
