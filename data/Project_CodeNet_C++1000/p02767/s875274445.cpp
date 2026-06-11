#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

int main() {
    int N;
    cin >> N;

    vector<int>X(N);
    int sum = 0;
    int P1,P2;
    int ans1 = 0;
    int ans2 = 0;

    for (int i=0; i<N; i++){
        cin >> X.at(i);
    }

    for (int i=0; i<N; i++){
        sum += X.at(i);
    }

    P1 = sum / N;
    P2 = P1 + 1;

    for (int i=0; i<N; i++){
        ans1 += (X.at(i)-P1)*(X.at(i)-P1);
        ans2 += (X.at(i)-P2)*(X.at(i)-P2);
    }

    if (ans1 <= ans2){
        cout << ans1 << endl;
    }
    else
    {
        cout << ans2 << endl;
    }
    
}
