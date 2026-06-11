/**
*    author:  souzai32
*    created: 23.08.2020 19:14:26
**/

#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
typedef long long ll;
#define mod 1000000007
using namespace std;

int main() {

    int n;
    cin >> n;
    vector<tuple<int,int>> p(n),q(n*(n+1)/2);
    int x,y;
    rep(i,n){
        cin >> x >> y;
        p[i]=make_tuple(x,y);
    }

    sort(all(p));
    int cost=0,count=0;
    int k=0;

    for(int i=0; i<n-1; i++){
        for(int j=n-1; j>i; j--){
            q[k]=make_tuple<int,int>(get<0>(p[j])-get<0>(p[i]),get<1>(p[j])-get<1>(p[i]));
            k++;
        }
    }

    for(int i=0; i<n*(n-1)/2; i++){
        for(int j=0; j<n*(n-1)/2; j++){
            if(q[i]==q[j]) count++;
        }
        cost=max(cost,count);
        count=0;
    }

    cout << n-cost << endl;

    return 0;
}