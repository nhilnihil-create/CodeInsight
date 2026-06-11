#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> P;
typedef pair<int, double> M;

bool compare_by_b(pair<int, double> a, pair<int, double> b) {
    if(a.second != b.second){
        return a.second < b.second;
    }else{
        return a.first < b.first;
    }
}

int main(){
    int h,n;
    cin >> h >> n;
    int a[n],b[n];
  int dekai = -1;
    vector<M> hoge;
    for(int i = 0; i < n; i++){
        int temp1,temp2;
        cin >> temp1 >> temp2;
        a[i] = temp1;
        b[i] = temp2;
      dekai = max(dekai,temp1);
    }
    int dp[h+dekai];
    for(int i = 0; i < h+dekai ; i++){
        dp[i] = MOD;
    }
    dp[0] = 0;
        //hoge.push_back(i,((double)temp1/temp2));
    //sort(hoge.begin(),hoge.end(),compare_by_b);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < h+dekai;j++){
            if(j+a[i] < h+ dekai){
                dp[j+a[i]] = min(dp[j+a[i]],dp[j]+b[i]);
            }
        }
    }
    int ans = MOD;
    for(int i = h; i < h+dekai;i++){
        ans = min(ans,dp[i]);
    }
    cout << ans << endl;




}