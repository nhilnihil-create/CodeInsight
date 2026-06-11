#include<bits/stdc++.h>
using namespace std;

int main(void) {
    int N, ans=0;
    cin >> N;
    int p[N];
    for(int i=0; i<N; i++){
      cin >> p[i];
     }

    for(int i=0; i<N-2; i++){
       if(p[i]<p[i+1] && p[i+1]<p[i+2])
          ans++;
        else if(p[i]>p[i+1] && p[i+1]>p[i+2])
          ans++;
     }

    cout << ans << endl;

    return 0;
}
