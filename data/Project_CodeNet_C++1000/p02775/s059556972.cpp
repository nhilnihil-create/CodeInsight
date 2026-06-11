/*|In The Name Of Allah|*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int N = 1e6+5;
const int mod = 1e9+7;

int n;
string s;
int mem[N][2];

int go(int idx , int carry){
    if(idx == -1)
        return carry;
    if(~mem[idx][carry])
        return mem[idx][carry];
    int c1 = (carry + s[idx] - '0') + go(idx - 1 , 0);
    int c2 = 10 - (carry + s[idx] - '0') + go(idx - 1 , 1);
    return mem[idx][carry] = min(c1 , c2);
}

int main(){
    cin >> s;
    n = s.size();
    memset(mem , -1 , sizeof mem);
    cout << go(n - 1 , 0);
}
