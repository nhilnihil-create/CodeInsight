#include <bits/stdc++.h>
#define ROOP(i, N) for(int i=0; i++; i<N)
#define RVROOP(i, N) for(int i=N; i--; i>=0)
#define ALL(v) v.begin(), v.end()
const int INF = 1e9;
const int MAX = 510000;
const int MOD = 1000000007;
const double PI = acos(-1);
using namespace std;
typedef long long ll;
typedef unsigned long long ull;

/*C++になってるか確認したほうがよくない？WOWWOW*/
/*DP使ったほうがよくない？？WOWWOW*/

int main(){
    int N; cin>>N;
    N%=10;
    string ans;
    if(N==3){
        ans="bon";
    }
    else if(N==0 || N==1 || N==6 || N==8){
        ans="pon";
    }
    else{
        ans="hon";
    }
    cout<<ans<<endl;
}