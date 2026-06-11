#include <bits/stdc++.h>
#define rep(i,n) for(int (i)=0;(i)<(int)(n);(i)++)
#define repeq(i,n) for(int (i)=0;(i)<=(int)(n);(i)++)
#define rep1(i,x,n) for(int (i)=(x);(i)<(int)(n);(i)++)
#define rep1eq(i,x,n) for(int (i)=(x);(i)<=(int)(n);(i)++)
#define rrep(i,x) for(int i=((int)(x)-1);i>=0;i--)
using namespace std;
using ll = long long;
using Int = long long;

const int MOD = 1000000007;
const ll INF = numeric_limits<ll>::max();
const int inf = 1e8;
typedef pair<int,int> P;

//少数点表示
//cout << std::fixed << std::setprecision(14) << 値

int main(){
    cin.tie( 0 ); ios::sync_with_stdio( false );
    int n;
    string s;
    cin >> n;
    cin >> s;

    if(n>=3200){
        cout << s << endl;
    }else{
        cout << "red" << endl;
    }
    return 0;

}