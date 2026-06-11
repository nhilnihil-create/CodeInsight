#include"bits/stdc++.h"
#include<unordered_set>
#include<unordered_map>
#include<random>
using namespace std;
typedef long long ll;
const ll MOD = (ll)(1e9+7);
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(), (x).end()
#define rep(i, n) for(int (i)=0; (i)<(n); (i)++)
int dx[4]={ 1,0,-1,0 };
int dy[4]={ 0,1,0,-1 };

struct Combination{
private:
    int N;
    long long M;
    vector<long long> f, i;
public:
    void init(int n, long long m){
        N = n; M = m;
        f.resize(N+1); f[0] = 0;
        i.resize(N+1); i[0] = 0;
        for(long long j=1; j<=N; j++){
            f[j] = f[j-1];
            long long tmp = j;
            while(tmp % 2 == 0){
                f[j]++;
                tmp /= 2;
            }
            i[j] = -f[j];
        }
    }
    long long C(int n, int r){
        //cout << n << " " << r << " " << f[n] << " " << i[r] << " " << i[n-r] << endl;
        if(f[n] + i[r] + i[n-r] > 0) return 0;
        else return 1;
    }
};

int N;
string S;

bool one = false;
int A[1000000];
Combination comb;

signed main(){
    cin >> N >> S;
    string T = "";
    rep(j, S.size()-1){
        T += (char)(abs(S[j]-S[j+1])+'0');
    }
    S = T;
    N--;\
    
    comb.init(N, 2);
    rep(i, N) one |= (S[i]=='1');
    if(one){
        // 答えは 0 か 1
        rep(i, N) A[i] = (S[i]-'0') % 2;
        int ans = 0;
        rep(i, N){
            if(comb.C(N-1, i) == 1) ans ^= A[i];
        }
        cout << ans << endl;
    }
    else{
        // 答えは 0 か 2
        rep(i, N) A[i] = (S[i]-'0') / 2;
        int ans = 0;
        rep(i, N){
            if(comb.C(N-1, i) == 1) ans ^= A[i];
        }
        cout << ans*2 << endl;
    }
}