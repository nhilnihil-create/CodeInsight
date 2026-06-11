#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i=0; i<N; i++)
    {
        cin >> A[i];
    }

    long long sum = 0;
    int m = 0;
    for (int i=0; i<N; i++)
    {
         m= max(m, A[i]);
        int s = m;
        sum += s - A[i];
    }

    cout << sum <<'\n';
}
