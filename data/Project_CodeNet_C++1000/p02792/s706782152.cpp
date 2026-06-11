#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <queue>
#include <map>
#define ll long long
using namespace std;
int main(){
    int n;
    cin>>n;
    char zero='0';
    string nstr=to_string(n);
    vector<vector<int>> cnt(10,vector<int>(10));
    for(int i=0;i<=n;i++){
        cnt[to_string(i)[0]-zero][to_string(i).back()-zero]++;
    }
    ll ans=0;
    for(int i=1;i<=9;i++){
        for(int j=1;j<=9;j++){
            ans+=cnt[i][j]*cnt[j][i];
        }
    }
    cout<<ans<<endl;
    return 0;
}