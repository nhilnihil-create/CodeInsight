#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, K, S;
    cin >> N >> K >> S;
    for(int i=0;i<K;i++){
        cout << S << " ";
    }
    if(S==1e+9) S=0;
    for(int i=K;i<N;i++){
        cout << (S+1) << " ";
    }
    cout << endl;

    return 0;
}