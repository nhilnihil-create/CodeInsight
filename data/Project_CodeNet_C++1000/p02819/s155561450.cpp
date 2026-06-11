#include <iostream>

using namespace std;

int main()
{
    bool check[100001];
    //vector<int> primes;
    for (int i=2; i<=100000; i++) {
        if (!check[i]) {
            //primes.push_back(i);
            for (int j=i+i; j<=100000; j+=i) {
                check[j] = true;
            }
        }
    }
    int x;
    int ans = 100003;
    cin >> x;
    for (int i=x; i<=100000; i++) {
        if (!check[i]) {
            ans = i;
            break;
        }
    }
   cout << ans << '\n';
   return 0;
}