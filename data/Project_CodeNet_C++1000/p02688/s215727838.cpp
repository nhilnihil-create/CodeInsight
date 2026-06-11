#include<bits/stdc++.h>
#define rep(i, n) for(int i=0; i<n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main(){
    int N, K;
    cin >> N >> K;

    int have[N]={0};
    rep(i, K){
        int d;
        cin >> d;
        rep(j, d){
            int A;
            cin >> A;
            have[A-1]=1;
        }
    }

    int sum=0;
    rep(i, N) if(have[i]==0) sum++;
    
    cout << sum << endl;
    
    return 0;
}