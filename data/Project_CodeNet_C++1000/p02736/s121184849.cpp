#include <bits/stdc++.h>
using namespace std;
using vi = vector<int>;
using vb = vector<bool>;
using vl = vector<long>;
using vs = vector<string>;
using vvi = vector<vector<int>>;
using vvb = vector<vector<bool>>;
using vvc = vector<vector<char>>;
using pii = pair<int, int>;
using pll = pair<long, long>;
#define fix20 cout << fixed << setprecision(20);
#define YES cout << "Yes" << endl;
#define NO cout << "No" << endl;
#define rep(i,n) for(int i=0; i<(int)(n);i++)
#define rrep(i,n) for(int i=(n)-1;i>=0;i--)
#define MOD 1000000007
#define all(vec) vec.begin(), vec.end()

int main(){
    int n;
    cin >> n;
    string s;
    cin >> s;
    vi data(n-1);
    bool one = false;
    rep(i,s.size()-1){
        data.at(i) = abs((s.at(i)-'0') - (s.at(i+1)-'0'));
        if(data.at(i) == 1) one = true;
    }
    int m = data.size();
    vi cnt(m,0);
    for(int i=1;i<30;i++){
        for(int j=1;j*pow(2,i)<m;j++){
            cnt.at(j*pow(2,i))++;
        }
    }
    vi sum(m,0);
    for(int i=1;i<m;i++){
        sum.at(i) = sum.at(i-1) + cnt.at(i);
    }
    int tmp = 0;
    rep(i,m){

        tmp += data.at(i) * (sum.at(m-1) - sum.at(m-1-i) - sum.at(i) == 0) % 2;
        tmp %= 2;
    }
    if(tmp == 1){
        cout << 1 << endl;
        return 0;
    }
    if(one){
        cout << 0 << endl;
        return 0;
    }
    tmp = 0;
    rep(i,m){
        tmp += (data.at(i)/2) * (sum.at(m-1) - sum.at(m-1-i) - sum.at(i) == 0) % 2;
        tmp %= 2;
    }
    if(tmp == 1){
        cout << 2 << endl;
    }else{
        cout << 0 << endl;
    }
}