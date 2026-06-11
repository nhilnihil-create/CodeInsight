#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <cstdlib>
#include <algorithm>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <unordered_map>
#include <functional>
#include <utility>
#include <tuple>
#include <cctype>
#include <bitset>
#include <complex>
#include <cmath>
#include <array>
#include <numeric>
using namespace std;
#define INF 0x3f3f3f3f
#define INFLL 0x3f3f3f3f3f3f3f3fLL
//#define mod 998244353
#define MOD 1000000007
#define mp make_pair
#define mt make_tuple
#define pb push_back
#define eb emplace_back
typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef pair<int, int> pint;
typedef pair<ll,ll> pll;
typedef tuple<int,int,int> tint;
typedef vector<int> vint;
typedef vector<ll> vll;
typedef vector<ull> vull;
typedef vector<pint> vpint;
int dx[8]={0,0,-1,1,1,1,-1,-1};
int dy[8]={-1,1,0,0,1,-1,1,-1};
const int SIZE=100050;
//templete
int main() {
    int N;
    cin>>N;
    vll A;
    ll sxor=0;
    for(int i=0;i<N;i++){
        ll a;
        cin>>a;
        A.pb(a);
        sxor^=a;
    }
    //総xorが1である桁は全部0にしとく
    for(int i=0;i<N;i++)
        A[i]&=~sxor;
    int r=0;    //現在のrank
    for(int idx=60;idx>=0;idx--){
        //idx桁目が1であるような要素を探す
        bool flag=0;    //そのような要素が見つかったか？
        for(int i=r;i<N;i++){
            if((A[i]>>idx)&1){
                swap(A[i],A[r]);    //見つけたら上に持ってくる
                flag=1;
                break;
            }
        }
        //A[r]以外でidx番目が1であるような要素すべてにA[r]をxorする
        if(flag){
            for(int i=0;i<N;i++){
                if(i!=r && ((A[i]>>idx)&1))
                    A[i]^=A[r];
            }
            r++;
        }
    }

    ll ans=0;
    for(int i=0;i<N;i++)
        ans^=A[i];
    cout<<2LL*ans+sxor<<endl;
    
    return 0;
}