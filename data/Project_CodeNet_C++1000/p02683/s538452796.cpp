#include <bits/stdc++.h>
using namespace std;

#include <bits/stdc++.h>
using namespace std;

typedef vector< vector<int> > vvi;
typedef vector< vector<bool> > vvb;
typedef vector< vector<char> > vvc;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef long long ll;

int main(){
    int n, m, x;
    cin >> n >> m >> x;
    vvi c_a(n,vi(m+1));
    for(int i=0;i<n;i++){
        cin >> c_a[i][0];
        for(int j=1;j<=m;j++){
            cin >> c_a[i][j];
        }
    }
    int ans = 1e9;
    for(int i=0;i<(1<<n);i++){
        vi temp(m+1,0);
        for(int j=0;j<n;j++){
            if((i>>j)&1) continue;
            for(int k=0;k<=m;k++){
                temp[k]+=c_a[j][k];
            }
            //cout << j << endl;
        }
        bool flag=true;
        //cout << " now i : " << i << endl;
        for(int j=1;j<m+1;j++){
            //cout << temp[j] << " ";
            if(temp[j]<x) flag = false;
        }
        //cout << endl;
        if(flag) ans=min(ans,temp[0]);
    }

    if(ans==1e9) cout << "-1" << endl;
    else cout << ans << endl;
    return 0 ;
}