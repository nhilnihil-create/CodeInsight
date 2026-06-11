#include<bits/stdc++.h>
#define int long long
using namespace std;

const int N = 1e5 + 8;

int score[N];

int32_t main(){
  ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);  

    int n , k , q;
    cin >> n >> k >> q;
    int u = 0;
    for(int i = 1 ; i <= q ; i++){
        int x; cin >> x;
        score[x]++;
        u++;
    }

    for(int i = 1 ; i <= n ; i++){
        cout << (k +  score[i] - u > 0 ? "Yes\n" : "No\n");
    }

  return 0;
}


