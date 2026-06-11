#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<cstdlib>
#include<queue>
#include<set>
#include<cstdio>

using namespace std;

#define ll long long
#define rep(i, n) for(int i = 0; i < n; i++)
#define P pair<int, int>

typedef vector<int> vec;
typedef vector<vec> mat;

ll abs_(ll x){
    if(x > 0) return x;
    else return -x;
}

int main(){
    ll x, k, d;
    cin >> x >> k >> d;
    ll mod = abs_(x) % d;
    if(abs_(x) / d > k){
        cout << abs_(x) - k * d << endl;
    }else{
        k -= abs_(x) / d;
        if(k % 2 == 0){
            cout << mod << endl;
        }else{
            cout << d - mod << endl;
        }
    }

}