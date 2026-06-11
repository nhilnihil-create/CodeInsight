#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=(ll)1e9+7;
const ll INF=(ll)1e18+10;
const double PI=acos(-1);

template<class T> bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T> bool chmin(T &a, const T &b) { if (a>b) { a=b; return 1; } return 0; }
int dy[]={-1,1,0,0};
int dx[]={0,0,-1,1};

bool check(const vector<int> &a){
    int maxi=a[0];
    for (int i = 1; i < a.size(); ++i) {
        if(a[i]<maxi) return false;
        maxi = a[i];
    }
    return true;
}

void solve(int cn) {
    int N; cin>>N;
    vector<int> a(N);
    for (int i = 0; i < N; ++i) {
        cin>>a[i];
    }

    if(check(a)){
        cout<<"YES"<<endl;
        return;
    }

    for (int i = 0; i < N; ++i) {
        for (int j = i+1; j < N; ++j) {
            swap(a[i],a[j]);
            if(check(a)){
                cout<<"YES"<<endl;
                return;
            }
            swap(a[i],a[j]);
        }
    }
    cout<<"NO"<<endl;

}


#define SINGLE
int main() {
#ifdef SINGLE
    solve(1);
#else
    int N;
    cin>>N;
    for(int i=0;i<N;++i){
        solve(i);
    }
#endif
    return 0;
}
