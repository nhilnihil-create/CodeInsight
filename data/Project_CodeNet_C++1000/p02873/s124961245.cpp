#include<iostream>
#include<cmath>
#include<algorithm>
#include<vector>
#include<functional>
#include<string>
#include<iomanip>
#include<map>
#include<utility>
#include<string>
#include<unordered_map>
#include<queue>

template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

using namespace std;

typedef long long ll;
typedef pair<int, int> P;
int gcd(int a, int b){return b ? gcd(b, a%b) : a;}
int lcm(int a, int b){return a*b / gcd(a, b);}

int all_sum(int a, int b){
    int sum = 0;
    for(int i = a; i <= b; i++){
        sum += i;
    }
    return sum;
}

int main(){
    string s;
    cin >> s;
    int n = s.size()+1;
    ll sum = 0;
    vector<int> a(n);
    for(int i = 0; i < n-1; i++){
        if(s[i] == '<') chmax(a[i+1], a[i]+1);
    }
    for(int i = s.size()-1; i >= 0; i--){
        if(s[i] == '>'){
            chmax(a[i], a[i+1]+1);
        }
    }
    for(int i = 0; i < n; i++) sum += a[i];
    cout << sum << endl;
    return 0;
}
