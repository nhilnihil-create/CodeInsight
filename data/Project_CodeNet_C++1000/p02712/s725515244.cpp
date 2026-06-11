#include <iostream>
#include <string>
#include <cstring>
using namespace std;
typedef long long ll;
const int maxn = 1e6;
ll ans[maxn];

void init() {
    memset(ans, 0, sizeof(ans));
    for (int i=1; i <= 1000000; i++) {
       ans[i]+=ans[i-1];
       if (i%3==0 || i%5==0) {
         continue;
       } else {
         ans[i]+=i;
       }
    }
}

int main () {
    init();
    int n;
    cin>>n;
    cout<<ans[n]<<endl;
    return 0;
}
