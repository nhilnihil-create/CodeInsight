#include <bits/stdc++.h>
using namespace std;

int main()
{
    int count = 0;
    int t=0;
    int N, X, Y;
    cin >> N >> X >> Y;
    int ans[N];


    for(int i=0; i<N; i++){
        ans[i]=0;
    }

    for(int i=1; i<=N; i++){
        for(int j=1; j<=N; j++){
            if(i<j){
                t = min(abs(j-i), abs(X-i)+1+abs(j-Y));
                t = min(t, abs(Y-i)+1+abs(j-X));
                ans[t]++;
            }
        }
    }
    
    for(int i=1; i<N; i++){
        cout << ans[i] << endl;
    }

    return 0;
}
