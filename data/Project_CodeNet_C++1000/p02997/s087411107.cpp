#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k; cin >> n >> k;
    if(k > (n-1)*(n-2)/2){
        cout << -1 << endl;
        return 0;
    }
    else{
        vector<pair<int, int>> tmp;
        int ans = 0;
        int cnt = (n-1)*(n-2)/2;
        //cout << cnt << endl;
        for(int i = 2; i <= n; i++){
            ans++;
            tmp.push_back(make_pair(1, i));
        }
        for(int i = 2; i < n; i++){
            if(cnt == k) break;
            for(int j = i + 1; j <= n; j++){
                tmp.push_back(make_pair(i, j));
                cnt--;
                ans++;
                if(cnt == k) break;
            }
        }
        cout << ans << endl;
        for(int i = 0; i < tmp.size(); i++) cout << tmp[i].first << " " << tmp[i].second << endl;
    }
}