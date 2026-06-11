#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<iomanip>
#include<utility>
#include<string>
#include<map>
#include<unordered_map>
#include<queue>

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

typedef long long ll;
typedef pair<int, int> Pi;
int gcd(int a, int b){return b ? gcd(b, a%b) : a;}
int lcm(int a, int b){return a*b / gcd(a, b);}


int main(){
    int n, k, s;
    cin >> n >> k >> s;

    vector<int> a(n);
    for(int i = 0; i < k; i++) a[i] = s;
    if(s == 1000000000){
        for(int i = k; i < n; i++) a[i] = 1;
    }
    else{
        for(int i = k; i < n; i++) a[i] = s+1;
    }

    for(int i = 0; i < n; i++) cout << a[i] << " ";
    cout << endl;
    return 0;
}
