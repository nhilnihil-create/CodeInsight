#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
    ll N, M ,Q, ans = 0;
    cin >> N >> M >> Q;
    vector<ll> a(Q,0);
    vector<ll> b(Q,0);
    vector<ll> c(Q,0);
    vector<ll> d(Q,0);
    vector<ll> A(11,1);

    for(int i = 0; i < Q; i++){
        cin >> a[i] >> b[i] >> c[i] >> d[i];
    }


    for(int i = 1; i <= M; i++){
        A[1] = i;
        for(int j = i ; j <= M; j++){
            A[2] = j;
            for(int k = j; k <= M; k++){
                A[3] = k;
                for(int l = k; l <= M; l++){
                    A[4] = l;
                    for(int m = l; m <= M; m++){
                        A[5] = m;
                        for (int n = m; n <= M; n++){
                            A[6] = n;
                            for(int o = n; o <= M; o++){
                                A[7] = o;
                                for(int p = o; p <= M; p++){
                                    A[8] = p;
                                    for(int q = p; q <= M; q++){
                                        A[9] = q;
                                        for(int r = q; r <= M; r++){
                                            A[10] = r;
                                            ll tmp_ans = 0;
                                            for(int num = 0; num < Q; num++){
                                                if(A[b[num]] - A[a[num]] == c[num]) tmp_ans += d[num];
                                            }
                                            ans = max(ans,tmp_ans);
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

