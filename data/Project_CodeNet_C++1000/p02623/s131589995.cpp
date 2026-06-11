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

int main(){
    int N,M,K;cin>>N>>M>>K;
    vector<ll> A(N+1),B(M+1);
    A[0] = 0;B[0] = 0;
    for(int i=0;i<N;i++){
        int a;cin>>a;
        A[i+1] = A[i] + a;
    }
    for(int i=0;i<M;i++){
        int b;cin>>b;
        B[i+1] = B[i] + b;
    }
    int ans = 0;
    int j = M;
    for(int i=0;i<=N;i++){
        if(A[i]>K) break;
        while(B[j]>K-A[i]) j--;
        ans = max(ans,i+j);
    }
    cout << ans << endl;
    return 0;
}