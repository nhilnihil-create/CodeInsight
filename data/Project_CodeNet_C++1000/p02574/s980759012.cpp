#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> P;
#define forin(in) for(int i=0; i<(int)in.size(); i++) cin>>in[i]
#define forout(out) for(int i=0; i<(int)out.size(); i++) cout<<out[i]<<endl
#define rep(i, n) for(int i=0; i<(n); i++)

bool pairwise = true;
vector<bool> seen(1e+6, false);

vector<pair<int, int> > prime_factorize(int n) {
    vector<pair<int, int> > res;
    for (int p = 2; p * p <= n; ++p) {
        if (n % p != 0) continue;
        int num = 0;
        while (n % p == 0) { ++num; n /= p; }
        if(seen[p - 1]) pairwise = false;
        res.push_back(make_pair(p, num)); seen[p - 1] = true;
    }
    if (n != 1){
        res.push_back(make_pair(n, 1));
        if(seen[n-1]){
            pairwise=false;
        }
        seen[n - 1] = true;
    }
    return res;
}


int gcd(int a, int b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}

int main(){
    int N; cin>> N;
    vector<int> A(N);
    bool setwise = true;

    cin>> A[0];
    int cur = A[0];

    for(int i = 1; i < N; i++){
        cin>> A[i];

        cur = gcd(cur, A[i]);
    }

    //setwise
    if(cur != 1) setwise = false;

    //pairwise
    rep(i, N){
        prime_factorize(A[i]);
    }

    //result
    if(pairwise){
        cout<< "pairwise coprime" << endl;
        return 0;
    }
    if(setwise){
        cout<< "setwise coprime" << endl;
        return 0;
    }
    cout<< "not coprime" << endl;
    return 0;
}
