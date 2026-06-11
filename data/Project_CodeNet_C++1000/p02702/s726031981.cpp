#include<bits/stdc++.h>
using namespace std;

int pow_mod(int a, int b, int c){ // a < 10^5
    if(b == 0) return 1;
    else if(b % 2 == 1) return a * pow_mod(a, b - 1, c) % c;
    else{
        int d = pow_mod(a, b / 2, c);
        return d * d % c;
    }
}

int main(){
    string S;
    cin >> S;
    vector<int> intS;
    for(char c : S) intS.push_back(c - 48);
    reverse(intS.begin(), intS.end());
    int Ssize = intS.size();
    vector<int> dp(Ssize);
    vector<int> rem(2019, 0);
    rem.at(0)++;
    dp.at(0) = intS.at(0);
    rem.at(intS.at(0))++;
    for(int i=1; i<Ssize; i++){
        int work = intS.at(i) * pow_mod(10, i, 2019);
        work = (work + dp.at(i - 1)) % 2019;
        dp.at(i) = work;
        rem.at(work)++;
    }
    int64_t cnt = 0;
    for(int i=0; i<2019; i++){
        int r = rem.at(i);
        if(r != 0)cnt += r * (r - 1) / 2;
    }
    cout << cnt << endl;
}