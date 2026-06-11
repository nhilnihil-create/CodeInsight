#include <iostream>
#include <algorithm>
using namespace std;

int main(void){
    int N, ubuf, vbuf;
    cin >> N;
    long long res = (long long)N*(N+1)*(2*N+4)/12;
    for(int i=0; i<N-1; i++){
        cin >> ubuf >> vbuf;
        res -= (long long)min(ubuf, vbuf)*(N-max(ubuf, vbuf)+1);
    }
    cout << res << endl;
}