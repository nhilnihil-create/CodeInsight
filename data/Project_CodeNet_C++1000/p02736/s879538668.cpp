#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
 
template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}
int comb(int n,int k){
    while(n!=0){
        if(n%2<k%2)return 0;
        n/=2;
        k/=2;    
    }
    return 1;
}
int main(){
    int n;
    string s;
    cin >> n >> s;
    int k = 0;
    rep(i,n){
        k += (s[i]-'0')*comb(n-1,i);
    }
    if(k%2==1){
        cout << 1 << endl;
        return 0;
    }
    vector<int>a(n-1);
    rep(i,n-1){
        a[i] = abs(s[i]-s[i+1]);
    }
    bool flag = 0;
    rep(i,n-1){
        if(a[i]==1){
            flag = 1;
        }
    }
    if(flag){
        cout << 0 << endl;
    }else{
        rep(i,n-1)a[i] /= 2;
        int z = 0;
        rep(i,n-1){
            z += a[i]*comb(n-2,i); 
        }
        if(z%2==0){
            cout << 0 << endl;
        }else{
            cout << 2 << endl;
        }
    }
    return 0;
}