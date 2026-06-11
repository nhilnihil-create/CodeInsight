#include <bits/stdc++.h>
using namespace std;
using pint = pair<int,int>;

const long long INFLL = 1LL << 60;
const int INFI = 1000000000;


int main(){
    int N;cin >> N;
    vector<long long> A(N);
    long long s = 0;
    for(int i=0;i<N;i++) {cin >> A[i]; s+=A[i];}
    long long m=s;
    long long l = 0; long long r = s;
    for(int i=0;i<N;i++) {
        l += A[i]; r -= A[i];
        if(abs(l-r) < m) m = abs(l-r);
    }
    cout << m << endl;
}
