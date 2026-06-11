#include <bits/stdc++.h>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstring>
#include <chrono>
#include <complex>
#define int long long int
#define vi vector<int>
#define vvi vector < vi >
#define pii pair<int,int>
#define mod 1000000007
#define inf 1000000000000000001
#define all(c) c.begin(),c.end()
#define mp(x,y) make_pair(x,y)
#define mem(a,val) memset(a,val,sizeof(a))
#define eb emplace_back
#define f first
#define s second
#define tr(k,st,en) for(int k = st; k <= en ; k++)

using namespace std;

bool isl (int k){
    while (k > 0) {
        int x = k%100;
        k/=10;
        if (k == 0) {
            break;
        }
        int y = x % 10;
        x/=10;
        if (abs(x-y) > 1) {
            return false;
        }
    }
    return true;
}

vector<int> facto(int x){
    vector<int> vec;
    int m = (int)sqrt(x);
    if (m == 1) {
        return vec;
    }
    for (int i = 2 ; i < m; i++) {
        if (x%i == 0) {
            vec.push_back(i);
            vec.push_back(x/i);
        }
    }
    if (m*m == x) {
        vec.push_back(m);
    } else if ( x% m == 0){
        vec.push_back(m);
        vec.push_back(x/m);
    }
    return vec;
}

bool check(int n,int k){
    int i = 0;
    while(n > 1 && i < 100){
        if (n%k==0) {
            n/=k;
        } else {
            n%=k;
        }
        i++;
    }
//    if (i==100) {
//        cout<<"i "<<endl;
//    }
    if (n == 1) {
        return true;
    }
    return false;
}

int32_t main()
{
    std::ios::sync_with_stdio(false);
    int n;
    cin>>n;
    auto fact1 = facto(n);
    auto fact2 = facto(n-1);
    int ans = 0;
    for (int k: fact1) {
        if (check(n, k)) {
            ans ++;
        }
    }
    for (int k: fact2) {
        if (check(n, k)) {
            ans ++;
        }
    }
    ans += 2;
    if(ans == 2){
        ans--;
    }
    cout<<ans<<endl;
    return 0;
}

