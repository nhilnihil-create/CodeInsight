#include <bits/stdc++.h>
using namespace std;


int main() {
    int N;
    int ans = 0;
    int s,t;

    cin >> N >> s; ans += s;
    for(int i=0;i<N-2;++i){
      cin >> t;
      ans += min(s,t);
      s = t;
    }
    cout << ans + s << endl;
    return 0;
}
