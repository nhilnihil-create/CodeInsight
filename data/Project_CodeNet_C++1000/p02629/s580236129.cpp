#include <bits/stdc++.h>
using namespace std;


int main(){
    long long N,D;
    cin >> N;
    vector<char>alpha = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z',};

    D = 26;
    int digit = 1;

    while(0 < N - D){
        N -= D;
        D *= 26;
        digit ++;
    }

    vector<char> Ans(digit);
    N--;
    D/=26;

    for(int i = 0; i < digit; i++){
        Ans[i] = alpha[N/D];
        N %= D;
        D /= 26;
    }
    
    for(int i = 0; i < Ans.size(); i++){
        cout << Ans[i];
    }

    cout << endl;
}
