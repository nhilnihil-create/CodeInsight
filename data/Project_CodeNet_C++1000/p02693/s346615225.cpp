#include<bits/stdc++.h>
#define endl '\n'
#define F first
#define S second
#define PB push_back
#define MP make_pair
#define FASTIO ios::sync_with_stdio(0); cin.tie(0);
#define REP(i,a,b) for(int i=a;i<b;i++)
const int inf=2e6;
#define maxx 16
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pi;
typedef pair<ll,ll> pll;


int main(){
    FASTIO;
    int k,a,b;
    cin>>k>>a>>b;
    REP(i,a,b+1){
      if(i%k==0){
        cout<<"OK";
        return 0;
      }
    }
    cout<<"NG"<<endl;
    return 0;
}
