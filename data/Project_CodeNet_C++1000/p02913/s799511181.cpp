#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <cstring>
#include <iomanip>
#include <random>
#include <chrono>
#include <queue>
#include <math.h>
#include <string>
#include <sstream>
#include <stack>
#define inf 1e9+7
#define pb push_back
#define make make_pair
#define kaku(a) cout << a << endl;
 
using namespace std;
 
#define ll long long
#define rep(i,n) for(ll i=0;i<n;i++)
#define PI 3.14159265359
long long gcd(long long a,long long b){ return b==0?a:gcd(b,a%b);}
long long lcm(long long a,long long b){ return a/gcd(a,b)*b;}
 
typedef pair<ll,ll> Pair;
const ll MAX_L=10000;
 



//Z[0]には0が入っている。これは適当にいじってもよい(以下のコードに影響はない)。
vector<ll> z_algorithm(string str){
    ll L = str.size();
    vector<ll> Z(MAX_L,0);
    for(int i=1, left=0, right=0; i<L; i++){
        if(i > right){
            left = right = i;
            for(;right < L && str[right-left] == str[right]; right++);
            Z[i] = right - left;
            right--;
        }
        else{
            int k = i - left;
            if(Z[k] < right - i + 1){
                Z[i] = Z[k];
            }
            else{
                left = i;
                for(;right < L && str[right-left] == str[right]; right++);
                Z[i] = right - left;
                right--;
            }
        }
    }
    return Z;
}

int main(){
    ll n;
    string s;
    cin >> n >> s;
    vector<ll> ans[MAX_L];
    for(ll i=0;i<n;i++){
        ans[i]=z_algorithm(s.substr(i));
    }
    ll answer=0;
    rep(i,n){
        for(ll j=0;j<ans[i].size();j++){
            if(ans[i][j]>j) ans[i][j]=j;
            answer=max(answer,ans[i][j]);
        }
    }
    kaku(answer);
}

