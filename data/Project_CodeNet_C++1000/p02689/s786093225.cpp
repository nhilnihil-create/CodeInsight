#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#define all(x) (x).begin(),(x).end()
typedef long long ll;

using namespace std;

int main()
{
    int N, M, sum;
    cin >> N >> M;
    std::vector<long> v(N), ans(N,1);

    for(int i = 0; i < N; i++){
        long H; cin >> H;
        v[i] = H;
    }
    for(int i=1; i <= M; i++){
        int A, B;   cin >> A >> B;
        if(v[A-1] > v[B-1]){
            ans[B-1] = 0;
        }else if(v[A-1] < v[B-1]){
            ans[A-1] = 0;
        }else{
            ans[A-1] = 0;
            ans[B-1] = 0;
        }
    }
    sum = 0;
    for(int i=0;i<N; i++){
        sum += ans[i];
    }
    
    cout << sum;
}