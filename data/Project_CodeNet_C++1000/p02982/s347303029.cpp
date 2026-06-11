#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define pb push_back
const int N = 2e5+5;
const ll mod = 1e9+7;
int pnt[12][12];
int n,d;
bool ch(int i, int j){
    int dis = 0;
    for(int k=0;k<d;k++){
        dis+=(pnt[i][k]-pnt[j][k])*(pnt[i][k]-pnt[j][k]);
    }
    for(int k=0;k<150;k++){
        if(k*k==dis)return true;
    }
    return false;
}
void solve(){
    cin>>n>>d;
    for(int i=0;i<n;i++){
        for(int j=0;j<d;j++){
            cin>>pnt[i][j];
        }
    }
    int ans = 0;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(ch(i,j))ans++;
        }
    }
    cout<<ans<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    int t=1;
  //  cin>>t;
    while(t--){
        solve();
    }
    return 0;
}
