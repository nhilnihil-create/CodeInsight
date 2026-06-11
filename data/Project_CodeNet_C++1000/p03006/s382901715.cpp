#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<(n); i++)
#define all(v) v.begin(),v.end()

using namespace std;
typedef long long ll;




int main()
{
    
    int N;
    cin >> N;
    vector<pair<int,int>> xy(N);
    rep(i,N) cin >> xy[i].first >> xy[i].second;
    sort(all(xy));
    
    int ans = 10000;
    if(N==1) ans = 1;
    
    for (int i = 0; i < N; i++) {
        for (int j = i+1; j < N; j++) {
            int x = xy[j].first - xy[i].first;
            int y = xy[j].second - xy[i].second;
            
            int an = 0;
            vector<bool> f(N, true);
            
            pair<int, int> a,b;
            
            for (int k = 0; k < N; k++) {
                if(f[k]){
                    an++;
                    f[k] = false;
                    a = xy[k];
                    for (int l = k+1; l < N; l++) {
                        if(f[l]){
                            b = xy[l];
                            if(a.first+x == b.first && a.second+y == b.second){
                                f[l] = false;
                                a = b;
                            }
                        }
                        
                    }
                }
                
            }
            ans = min(an,ans);
            
        }
    }
    cout << ans << endl;
    
    return 0;
}

