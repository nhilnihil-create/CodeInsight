#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<map>
#define all(x) (x).begin(),(x).end()
#define print(x) cout << (x) << endl
typedef long long ll;
const ll MOD = 1000000007;
const ll MOD2 = 998244353;
 
using namespace std;

int main(){
    int N;  cin >> N;
    vector<int> v(N);
    for(int i=0; i<N; i++)  cin >> v[i];
    sort(all(v));
    int ans[N-1][2];
    int tmp;
    if(v[0] >= 0 && v[N-1] >= 0){
        tmp = v[0];
        for(int i=0; i<N-2; i++){
            ans[i][0] = tmp;
            ans[i][1] = v[i+1];
            tmp -= v[i+1];
        }
        ans[N-2][0] = v[N-1];
        ans[N-2][1] = tmp;
        tmp = v[N-1] - tmp;
    }else if(v[0] <= 0 && v[N-1] >= 0){
        for(int i=0; i<N; i++){
            if(v[i] >= 0){
                for(int j=i; j<N-1; j++){
                    ans[j-i][0] = v[0];
                    ans[j-i][1] = v[j];
                    v[0] -= v[j];
                }
                for(int j=0; j<i; j++){
                    ans[N-1-i+j][0] = v[N-1];
                    ans[N-1-i+j][1] = v[j];
                    v[N-1] -= v[j];
                }
                tmp = v[N-1];
                break;
            }
        }
    }else{
        for(int i=N-1; i>0; i--){
            ans[N-1-i][0] = v[N-1];
            ans[N-1-i][1] = v[i-1];
            v[N-1] -= v[i-1];
        }
        tmp = v[N-1];
    }
    print(tmp);
    for(int i=0; i<N-1; i++)    cout << ans[i][0] << " " << ans[i][1] << endl;
}