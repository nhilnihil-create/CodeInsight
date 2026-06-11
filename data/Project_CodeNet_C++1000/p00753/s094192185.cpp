#include <iostream>
#include <vector>
using namespace std;

constexpr int MAX = 123456 * 2;
bool prime[MAX+1] = {false};

void eratos() {
    for(int i = 0; i <= MAX; ++i) {
        prime[i] = true;
    }

    for(int i = 2; i*i <= MAX; ++i) {
        if(prime[i]) {
            for(int j = i*i; j <= MAX; j = j+i) {
                prime[j] = false;
            }
        }
    }
    prime[0] = false;
    prime[1] = false;
}

int check(int min) {
    int ans = 0;
    for (int i = min+1; i < min * 2 + 1; ++i) {
        if (prime[i]) ans++;
    }
    return ans;
}

int main() {
    int n;
    eratos();
    while(cin>>n, n) {
        cout<<check(n)<<endl;
    }
    return 0;
}