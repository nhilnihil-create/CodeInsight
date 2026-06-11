#include <iostream>//cout<<right で右揃え
#include <iomanip>//cout<<setw(数字) で空白による桁揃え
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <cstdlib>//abs()で整数絶対値
#include <cmath>//abs()かfabs()で少数絶対値
#include <functional>//sort第三引数greater<型名>()で降順
#include <map>

using namespace std;
using ll = long long int;

#define M 1000000007

ll power_mod(ll a,ll index,ll divider){
    ll ret = 1;
    for(;index>0;index/=2,a=a*a%divider){
        if(index%2==1){
            ret = ret * a % divider;
        }
    }
    return ret;
}

int main(){
    int N,B;cin>>N>>B;
    int R = N - B;
    vector<ll> fuctorial_mod(N+1);
    fuctorial_mod[0] = 1;
    ll fuctorial = 1;
    for(int i=1;i<=N;i++){
        fuctorial = fuctorial * i % M;
        fuctorial_mod[i] = fuctorial;
    }
    for(int i=1;i<=B;i++){
        if(i>R+1){
            cout << 0 << endl;
            continue;
        }
        ll R_ans = fuctorial_mod[R+1] * power_mod(fuctorial_mod[i],M-2,M) % M;
        R_ans = R_ans * power_mod(fuctorial_mod[R+1-i],M-2,M) % M;
        ll B_ans = fuctorial_mod[B-1] * power_mod(fuctorial_mod[i-1],M-2,M) % M;
        B_ans = B_ans * power_mod(fuctorial_mod[B-i],M-2,M) % M;
        cout << R_ans * B_ans % M << endl;
    }
    return 0;
}