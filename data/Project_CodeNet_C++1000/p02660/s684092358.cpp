#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    unsigned long long int N;
    cin >> N;
    
    if(N == 1){
        cout << 0 <<endl;
        return 0;
    }
    vector<bool> isPrime((int)sqrt(N) + 1, true);
    int maxv = sqrt(N);
    int ans = 0;
    for(int i = 2; i <= maxv; i++){
        if(isPrime[i] == false)    continue;
        int count = 0;
        while(N % i == 0){
            count++;
            N /= i;
        }
        if(count == 0)  continue;
        int sum = 0;
        for(int j = 1; (sum += j) <= count ; j++){
            ans++;
        }
        
        for(int j = i; j <= maxv; j+=i){
            isPrime[j] = false;
        }
    }
    if(N != 1)  ans++;
    cout << ans << endl;
    return 0;
}