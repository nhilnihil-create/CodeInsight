#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    
    int cnt = 0;
    for(int A=1; A<N; A++){
        for(int B=1; A*B<N; B++){
            if(N-A*B > 0) cnt++;
        }
    }

    cout << cnt << endl;
    
}