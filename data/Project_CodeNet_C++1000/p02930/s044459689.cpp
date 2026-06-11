#include<bits/stdc++.h>
using namespace std;
typedef long long ll;



signed main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(20);

    int n;
    cin>>n;
    int a[n][n];
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i==j) continue;
            int bit = 1;
            int cnt = 0;
            while(true){
                cnt++;
                if(((i&bit) ^ (j&bit)) == bit){
                    a[i][j] = cnt;
                    break;
                }
                bit = (1<<cnt);
                // cerr << cnt << " " << bit << " " << (i&bit) << " " << (j&bit) << endl;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}