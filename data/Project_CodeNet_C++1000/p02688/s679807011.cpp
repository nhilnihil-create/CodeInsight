#include<bits/stdc++.h>
using namespace std;
#define ll  long long 
#define INF 999999999
#define rep(i,n) for(int i=0;i<n;i++)
const ll MOD = 1000000007;
ll cnt =0,ans=0;
const int MAX = 510000;

int main(){
    int n,k;
    map<int,int>mp;
    cin >> n >> k;
    int d[110],a[110][110];
    for(int i=1;i<=k;i++){
        cin >> d[i];
        for(int j=1;j<=d[i];j++){
            cin >> a[i][d[i]];
            mp[ a[i][d[i]] ]++;
        }
    }

    for(int i=1;i<=n;i++){
       // cout << "i= " << i << " mp[i] = " << mp[i] << endl;
        if(mp[i] == 0)cnt++;
    }
    cout << cnt << endl;


}
       
