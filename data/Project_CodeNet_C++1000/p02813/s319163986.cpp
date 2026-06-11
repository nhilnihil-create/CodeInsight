#include <bits/stdc++.h>
using namespace std;

#define rep(i,n) for(int i=0;i<(n);i++)

typedef long long ll;

#define REP(i,n) for(ll i=0;i<(ll)(n);i++)
#define REPD(i,n) for(ll i=n-1;i>=0;i--)
#define FOR(i,a,b) for(ll i=a;i<=(ll)(b);i++)
#define FORD(i,a,b) for(ll i=a;i>=(ll)(b);i--)
//定数
#define INF 1000000000 //10^9:極めて大きい値,∞
//略記
#define PB push_back //vectorヘの挿入
#define MP make_pair //pairのコンストラクタ
#define F first //pairの一つ目の要素
#define S second //pairの二つ目の要素

void printVector(const vector<int>& vec) {
    for (int value : vec) {
        cout << value << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cin>>n;
    vector<string> s(2);
//    rep(i,2) cin>>s[i];
    vector<int> nums(n), d(2);
    vector<vector<int>> x(2, vector<int>(n));
    rep(i,2){
        rep(j,n){
            cin>>x[i][j];
        }
    }
    rep(i,n) nums[i]=i+1;
    int c=0;
    do {
        rep(i,2){
            bool b=true;
            rep(j,n){
                b&=nums[j]==x[i][j];
            }
            if(b) d[i]=c;
        }
        c++;
    } while (next_permutation(nums.begin(), nums.end()));
    cout<<abs(d[0]-d[1])<<endl;
    return 0;
}