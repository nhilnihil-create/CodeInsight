#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
#include <cstdint>
using namespace std;
using vi = vector<int>;
using i64 = int64_t;

int main(void){
    int n;
    i64 k;
    cin >> n >> k;
    vi A(n+1), hist(n+1);
    for(int i=1; i<=n; i++) cin >> A[i];
    int now = 1, count = 0;
    hist[1] = 1;
    for(int i=1; i<=k; i++){
        now = A[now];
        hist[now]++;
        if(hist[now]==2) count++;
        if(hist[now]==3)  k = i+(k-i)%count;
    }
    cout << now << '\n';
    return 0;
}