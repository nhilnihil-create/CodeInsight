#include<bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int (i)=0;(i)<(n);i++)
#define INF 1001001001
#define LLINF 1001001001001001001
#define MOD 1000000007
#define FOUT(n, dist) cout<<fixed<<setprecision(n)<<(dist);
#define BR cout<<endl;
#define LEN(s) s.length();
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
#define ALL(v) v.begin(), v.end()
typedef long long ll;
const ll mod=1000000007;

int main(){
    int n;
    cin >> n;

    int d1[n], d2[n];
    rep(i,n){
        cin >> d1[i] >> d2[i];
    }

    int count = 0;

    for(int i = 0; i < n; i++){
        if(d1[i] == d2[i]){
            count++;
        }
        else {
            count = 0;
        }

        if(count == 3){
            cout << "Yes" << endl;
            return 0;
        }
    }

    cout << "No" << endl;
    return 0;
}

