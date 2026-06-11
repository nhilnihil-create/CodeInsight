#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
#include<queue>
#define all(x) (x).begin(),(x).end()
typedef long long ll;

using namespace std;

int main(){
    int N, M, atr, btr;  cin >> N;
    M = N/2;
    vector<ll> v(N), a(M+1),b(M);
    for(int i=0; i<N; i++)    cin >> v[i];
    a[0] = 0;
    b[0] = 0;
    for(int i=0; i<N; i++){
        if(i == 0)  a[M] = v[N-1] - v[0];
        else if(i == N-1)    break;
        else if(i%2 == 1)    a[i/2+1] = a[i/2] + v[i] - v[i-1];
        else if(i%2 == 0)   b[i/2] = b[i/2-1] + v[i] - v[i-1];
    }
    btr = -(v[N-1] - v[N-2] - v[0] + b[M-1])/2;
    atr = v[0] - btr;
    for(int i=0; i<M+1; i++){
        if(i < M){
            cout << 2*(atr + a[i]) << " " << 2*(btr + b[i]) << " ";
        }else   cout << 2*(atr + a[i]);
    }
}