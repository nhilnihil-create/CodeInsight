#include<bits/stdc++.h>

#define _GLIBCXX_DEBUG
#define all(v) (v).begin(),(v).end()

using namespace std;

using ll=long long;
using pii=pair<int, int>;
using vi=vector<int>;

const ll LINF=1LL<<60;
const int INF=1<<29;
const int MOD=2019;

int a, b, c;
int K; 

bool rec(int n){
    if(n == 0){
        if(b > a && c > b) return 1;
        else return 0;
    }
    a*=2;
    if(rec(n-1)) return 1;
    a/=2;
    b*=2;
    if(rec(n-1)) return 1;
    b/=2;
    c*=2;
    if(rec(n-1)) return 1;
    c/=2;
    return 0;
}

int main(){
    cin >> a >> b >> c;
    cin >> K;
    cout << (rec(K)?"Yes":"No") << endl; 
    return 0;
}