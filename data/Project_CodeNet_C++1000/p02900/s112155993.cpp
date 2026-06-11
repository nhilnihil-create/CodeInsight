
#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

long long gcd(long long a, long long b) {
   if (a%b == 0) return b;
   else return gcd(b, a%b);
}

vector<long long> divisor(long long n) {
    vector<long long> ret;
    for (long long i = 1; i * i <= n; i++) {
        if (n % i == 0) {
            ret.push_back(i);
            if (i * i != n) ret.push_back(n / i);
        }
    }
    sort(ret.begin(), ret.end());
    return ret;
}

int main(){
    long long a, b;
    cin >> a >> b;

    long long g = gcd(a, b);

    vector<long long> div = divisor(g);
    long long n = (long long) div.size();
    vector<bool> flag(n, true);
    

    for(long long i = 1; i < n; i++){
        if(flag[i] == false) continue;
        for(long long j = i+1; j < n; j++){
            if(div[j] % div[i] == 0) flag[j] = false;
        }
    }

    long long cnt = 0;
    for(long long i = 0; i < n; i++){
        if(flag[i] == true) cnt++;
    }
    cout << cnt << endl;
    return 0;
}