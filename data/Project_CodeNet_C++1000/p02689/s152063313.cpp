#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;

int main(void){
    int n, m;
    cin >> n >> m;
    vi H(n), A(n, 1);
    for(int &h : H) cin >> h;
    for(int i=0; i<m; i++){
        int a, b;
        cin >> a >> b;
        a -= 1; b -= 1;
        if(H[a]<=H[b]) A[a] = 0;
        if(H[b]<=H[a]) A[b] = 0;
    }
    int cnt = 0;
    for(int &a : A) cnt += a;
    cout << cnt << '\n';
    return 0;
}