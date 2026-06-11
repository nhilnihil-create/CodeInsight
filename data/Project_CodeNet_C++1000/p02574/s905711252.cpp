#include<bits/stdc++.h>

#define fast ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define int long long
#define endl '\n'

using namespace std;

const int N = 2e6 + 77 ;
int cnt[N] , g;

int32_t main(){
    fast;
    int n ; cin >> n ;
    bool pp = true;
    for(int i = 0 ; i < n ; ++i){
        int a ; cin >> a ;
        g = __gcd(g,a);
        cnt[a]++;
    }

    for(int i = 2 ; i < N ; ++i){
        int sum = 0;
        for(int j = i ; j < N ; j += i) sum += cnt[j];
        if(sum > 1) {pp = false;break;}
    }

    if(pp) cout << "pairwise coprime" << endl;
    else if(g==1) cout << "setwise coprime" << endl;
    else cout << "not coprime" << endl;
    return 0;
}