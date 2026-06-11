#include<bits/stdc++.h>
using namespace std;
#define int long long
#define M 1000000007
#define INF ((1LL<<62LL) - 1)

const int N = 1000005;

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> a[15][10];

    int total = 9;
    for(int i=0;i<=9;i++){
        a[1][i].push_back(i);
    }

    int ten = 10;
    for(int i=2;i<=12;i++){
        for(int j = 0;j<=9;j++){
            for(int k = max(0LL,j-1);k<=min(9LL,j+1);k++){
                for(int x : a[i-1][k]){
                    a[i][j].push_back(j*ten + x);
                    total++;
                    if(total > N) break;
                }
                if(total > N) break;
            }
            if(total > N) break;
        }
        if(total > N) break;
        ten*=10;
    }

    vector<int> ans;
    for(int i=1;i<=12;i++){
        for(int j=1;j<=9;j++){
            //cout << "digits " << i << " starting with " << j << "\n";
            for(int x: a[i][j]){
                //cout << x << " ";
                ans.push_back(x);
            }
            //cout << endl << endl;
        }
    }

    int k; cin >> k;
    sort(ans.begin(), ans.end());
    //for(int x : ans) cout << x << " ";
    //cout << "\n";
    cout << ans[k-1] << "\n";




}
