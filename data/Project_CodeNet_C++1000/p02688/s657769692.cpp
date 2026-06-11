#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < int n; i++)
static const long long INF = 1000000;
using p = pair<int,int>;

int main(){
    int n,k;
    cin >> n >> k;
    vector<int> vec(n,0);
    for (int i = 0; i<k; i++){
        int d;
        cin >> d;
        for (int j = 0; j < d; j++){
            int x;
            cin >> x;
            if (vec[x-1] == 0){
                vec[x-1] = 1;
            }            
        }
    }
    int ans = 0;
    for (int i = 0; i < n; i++){
        if (vec[i] == 0){
            ans++;
        }
        
    }
    cout << ans << endl;
    
}