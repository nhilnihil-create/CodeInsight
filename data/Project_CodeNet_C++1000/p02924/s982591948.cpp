#include<bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    cin >> N;
    long long res=0;
    for (long long i=1; i<N; i++) res+=i;
    cout << res;
}