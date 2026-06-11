#include <vector>
#include <bitset>
#include <iostream>
using namespace std;

void makePrimeNumber(int N, vector<bool>& prime)
{
    prime.assign(N+1, true);
    prime[0] = prime[1] = false;
    for(int i=2; i*i<=N; ++i){
        if(prime[i]){
            for(int j=i; i*j<=N; ++j){
                prime[i*j] = false;
            }
        }
    }
}

int main()
{
    vector<bool> prime;
    makePrimeNumber(123456 * 2, prime);

    for(;;){
        int a;
        cin >> a;
        if(a == 0)
            return 0;

        int ret = 0;
        for(int i=a+1; i<=2*a; ++i){
            if(prime[i])
                ++ ret;
        }
        cout << ret << endl;
    }
}