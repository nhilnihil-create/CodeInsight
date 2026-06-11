#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); ++i )
typedef std::pair<int,int> pint;

using namespace std;
typedef long long ll;

int main(){
    int N; cin >> N;
    vector<int> list(N);
    ll money = 1000;
    ll stock = 0;
    rep (i,N){
        cin >> list[i];
    }
    rep (i,N-1){
        if(list[i] < list[i+1]){
            stock = money / list[i];
            money = money - list[i] * stock + list[i+1] * stock;
            stock = 0;
        }
    }
    cout << money << endl;
    return 0;
}