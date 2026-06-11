#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (n); ++i)

using namespace std;
using ll = long long;
using v1 = vector<int>;
using vl = vector<long long>;
using v2 = vector<vector<int>>;
using v3 = vector<vector<char>>;

int main(){
    int n;
    cin >> n;
    int ans = 0;
    int m = 0;
    int preH;
    cin >> preH;
    for(int i = 1;i<n; i++){
        int H;
        cin >> H;
        if(H <= preH){
            m++;
            ans = max(ans, m);
        }else{
            ans = max(ans, m);
            m = 0;
        }
        preH = H;
    }
    cout << ans << endl;
}