#include <bits/stdc++.h>
using namespace std;

long long binary(long long bina,long long k){
    long long ans = 0;
    for (long long i = 0; bina>0 ; i++)
    {
        bina = bina/k;
        ans++;
    }
    return ans;
    //to_string(ans).size();
}

int main() {
    //
    long long num,k;
    string kekka;
    cin >> num >> k;
    long long size = binary(num, k);

    cout << size;

    //
}
