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

int main(){
    int N, K;   cin >> N >> K;
    vector<int> a(N);
    for(int i=0; i<N; i++)  cin >> a[i];

    int l, r;
    for(int i=0; i<min(K,50); i++){
        vector<int> tmp(N,0);
        for(int j=0; j<N; j++){
            l = max(j - a[j], 0);
            r = min(j + a[j] + 1, N);
            tmp[l]++;
            if(r < N)   tmp[r]--;
        }
        for(int j=1; j<N; j++)  tmp[j] += tmp[j-1];
        a = tmp;
    }
    for(int i=0; i<N; i++)  cout << a[i] << " ";
}