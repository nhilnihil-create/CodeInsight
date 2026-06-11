#include<iostream>
#include<algorithm>
using namespace std;


long long mypow(int p, int n) {
    if (n == 0) return 1;
    long long t = mypow(p, n / 2);
    return n & 1 ? t * t * p : t * t;
}


long long N;

void read() {
    cin >> N;
}


void work() {
    int len = 1;

    --N;
    while (N >= mypow(26, len)) {
        N -= mypow(26, len);
        ++len;
    }

    string ans;
    for (int i = 0; i < len; ++i) {
        ans += (char)(N % 26 + 'a');
        N /= 26;
    }
    reverse(ans.begin(), ans.end());
    
    cout << ans << endl;
}


int main() {
    read();
    work();
    return 0;
}
