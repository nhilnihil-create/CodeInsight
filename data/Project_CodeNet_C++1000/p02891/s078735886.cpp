#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    string S;
    ll K;
    cin >> S >> K;

    ll n = S.size();


    ll leftSeq = 0;
    ll rightSeq = 0;

    
    for (int i = 0; i < n; i++)
    {
        if (S[i] == S[0])
            leftSeq++;
        else
            break;
    }

    if(leftSeq == n){
        cout << n * K / 2 << endl;
        return 0;
    }

    for (int i = n-1; i >= 0; i--)
    {
        if (S[i] == S[n - 1])
            rightSeq++;
        else
            break;
    }

    ll singleCnt = 0;
    char val = S[0];
    int seq = 1;
    for(int i = 1; i <= n; i++){
        if(val == S[i]) {
            seq++;
        } else {
            singleCnt += seq/2;
            val = S[i];
            seq = 1;
        }
    }

    if(rightSeq%2 == 1 && leftSeq %2 == 1 && K%2 == 0){
        cout << ((singleCnt + 1 ) * K) - 1 << endl;
    } else {
        cout << singleCnt * K << endl;
    }

    return 0;
}
