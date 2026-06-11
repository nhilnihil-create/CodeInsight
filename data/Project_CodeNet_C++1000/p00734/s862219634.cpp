#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 1e9+7;
main(){
    int N,M;
    cin >> N >> M;
    while(N){
        int suma = 0,sumb = 0;
        vector<int> A(N),B(M);
        rep(i,0,N){cin >> A[i];suma += A[i];}
        rep(i,0,M){cin >> B[i];sumb += B[i];}
        int mini = INF,ai,bi;
        rep(i,0,N)rep(j,0,M){
            int na = suma - A[i] + B[j];
            int nb = sumb + A[i] - B[j];
            if(na == nb){
                if(mini > A[i] + B[j]){
                    ai = A[i];
                    bi = B[j];
                    mini = A[i] + B[j];
                }
            }
        }
        if(mini != INF)cout << ai << " " << bi << endl;
        else           cout << -1 << endl;
        cin >> N >> M;
    }
}
