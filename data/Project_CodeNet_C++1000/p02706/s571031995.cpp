#include <bits/stdc++.h>

using namespace std;

int main()
{

    int N, M;
    cin >> N >> M;

    int assignment = 0;

    for (int i = 1; i <= M; i++){
       int A; cin >> A;
       assignment +=A;
    }
    if (assignment <= N){
        cout << N - assignment << "\n";
    }
    else cout << "-1\n";

    return 0;
}
