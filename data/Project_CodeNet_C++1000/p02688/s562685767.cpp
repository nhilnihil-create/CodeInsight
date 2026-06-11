#include<bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define REP(i,a,b) for(int i=a;i<b;i++)

using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;

bool vis[105];
int main(){
    FASTIO;
    int n,k,d,a,cnt=0;
    cin>>n>>k;
    REP(i,0,k){
      cin>>d;
      REP(i,0,d){
        cin>>a;
        if(!vis[a]){
            cnt++;vis[a]=1;
        }
      }
    }
    cout<<n-cnt<<endl;
    return 0;
}
