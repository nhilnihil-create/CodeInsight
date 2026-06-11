#include <bits/stdc++.h>
#include <string>
#include <vector>
#define rep(i,n) for (int i = 0;i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
int INF = 1e9;



int main(){
    int n,m,q;
    cin >> n >> m >> q;
    int query[50][4];
    rep(i,q) cin >> query[i][0] >> query[i][1] >> query[i][2] >> query[i][3];

    auto score = [&](const int *a){
        int ret = 0;
        rep(i,q){
            int b=query[i][0]-1;
            int c = query[i][1]-1;
            if(a[c]-a[b]==query[i][2]) ret += query[i][3];
        }
        return ret;
    };

    int ans = 0;
    for(int a1=1;a1<=m;a1++){
        for(int a2=a1;a2<=m;a2++){
            for(int a3=a2;a3<=m;a3++){
                for(int a4=a3;a4<=m;a4++){
                    for(int a5=a4;a5<=m;a5++){
                        for(int a6=a5;a6<=m;a6++){
                            for(int a7=a6;a7<=m;a7++){
                                for(int a8=a7;a8<=m;a8++){
                                    for(int a9=a8;a9<=m;a9++){
                                        for(int a10=a9;a10<=m;a10++){
                                            int a[10] = {a1,a2,a3,a4,a5,a6,a7,a8,a9,a10};
                                            ans = max(ans,score(a));
                                        }
                                    }
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    cout << ans << endl;
}