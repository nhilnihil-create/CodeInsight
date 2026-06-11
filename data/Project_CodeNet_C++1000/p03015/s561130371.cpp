#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

const int p = 1000000007;

long long pow3[100100];
long long pow2[100100];

int main(){
    pow3[0] = 1;
    pow2[0] = 1;
    for(int i =0; i < 100050; i++){
        pow3[i + 1] = pow3[i]*3%p;
        pow2[i + 1] = pow2[i]*2%p;
    }
    string s;
    cin >> s;
    reverse(s.begin(),s.end());
    vector<int> ones;
    for(int i = 0; i < s.size(); i++){
        if(s.at(i) == '1') ones.push_back(i);
    }
    long long ans = 0;
    int n = ones.size();
    for(int i = 0; i < n; i++){
        ans += (pow2[n - 1 - i]*pow3[ones[i]])%p;
        ans %= p;
    }
    ans += pow2[n];
    ans %= p;
    cout << ans << endl;
}