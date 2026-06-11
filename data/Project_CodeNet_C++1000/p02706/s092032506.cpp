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
#define trb(k,en,st) for(int k = en; k >= st ; k--)
using namespace std;

//int n = 2;
//
//void add_self(int& a, int b){
//    a += b;
//    if (a >= mod) {
//        a-=mod;
//    }
//}
//
//int mul(int a, int b){
//    int c = a*b;
//    return c%mod;
//}
//
//struct M {
//    vector<vector<int>> t;
//    M(){
//        t.resize(n, vector<int>(n));
//    }
//    M operator * (M& b){
//        M c;
//        tr(i,0, n-1){
//            tr(j,0,n-1){
//                tr(k,0,n-1){
//                    add_self(c.t[i][j] , mul(t[i][k] ,b.t[k][j]));
//                }
//            }
//        }
//        return c;
//    }
//};
//M power(M x, int k){
//    M ans;
//    tr(i,0,n-1){
//        ans.t[i][i] = 1;
//    }
//    while (k) {
//        if (k%2) {
//            ans = ans * x;
//        }
//        x = x*x;
//        k/=2;
//    }
//    return ans;
//}


int32_t main()
{
    std::ios::sync_with_stdio(false);
    int n,m,sum;
    cin>>n>>m;
    tr(i,0,m-1){
        cin>>sum;
        n-=sum;
    }
    cout<< ( n >= 0 ? n : -1 )<<endl;
    return 0;
}


