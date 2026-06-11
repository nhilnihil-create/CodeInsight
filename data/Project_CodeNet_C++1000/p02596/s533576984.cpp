#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
using namespace std;
using vi = vector<int>;

int main(void){
    int k;
    cin >> k;
    vi a(k+1);
    a[1] = 7%k;
    for(int i=2; i<=k; i++) a[i] = (a[i-1]*10+7)%k;
    for(int i=1; i<=k; i++)if(a[i]==0){
        cout << i << '\n';
        return 0;
    }
    cout << -1 << '\n';
    return 0;
}