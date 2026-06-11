#include <bits/stdc++.h>
//deeply ingrained
using namespace std;


int main() {

    long long n;
    long long answer = 0;
    cin>>n;
    long long tmp_n = n;
    for(long long i=2;i*i<=n;i++) {
        long long tmp = i;
        while(tmp_n % tmp == 0) {
            tmp_n/=tmp;
            answer++;
            tmp*=i;
        }
        while(tmp_n % ((long long)i) == 0) {
            tmp_n/=i;
        }
    }
    cout<<answer + (tmp_n > 1)<<endl;
    return 0;
}

