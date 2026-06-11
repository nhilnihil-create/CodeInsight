/*
      author : Nishikawa
      created: 10.08.2020 13:05:55
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    int n,k;
    cin >> n >> k;
    vector<bool> have(n,true);
    for(int i=0; i<k; i++){
        int d;
        cin >> d;
        for(int j=0; j<d; j++){
            int a;
            cin >> a;
            --a;
            have[a]=false;
        }
    }
    int ans = 0;
    for(int i=0; i<n; i++){
        if(have[i]) ans++;
    }
    cout << ans << endl;
    return 0;
}
