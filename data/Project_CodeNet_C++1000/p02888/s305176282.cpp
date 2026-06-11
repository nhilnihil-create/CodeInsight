#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#include<numeric>
#define all(x) (x).begin(),(x).end()
typedef long long ll;
const ll MOD = 1000000007;
 
using namespace std;

int main()
{
    int N;  cin >> N;
    vector<int> v(N);
    for(int i=0; i<N; i++)  cin >> v[i];
    sort(all(v));
    int ans = 0;
    for(int i=0; i<N-2; i++){
        for(int j=i+1; j<N-1; j++){
            for(int k=j+1; k<N; k++){
                if(v[k] < v[i] + v[j])  ans++;
                else    break;
            }
        }
    }
    cout << ans << endl;
    return 0;
}