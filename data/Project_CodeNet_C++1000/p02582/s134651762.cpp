#include<bits/stdc++.h>
using namespace std ;
const int N= 3e5;
int Mod = 1e9+7 ;
long long cum [N];


int main(){
    string N;
    cin >> N;
    int ans = 0;
    int tmp = 0;
    for (int i = 0; i < N.length(); ++i) {
        if (N[i] == 'R') {
            tmp++;
            ans = tmp;
        } else {
            if (ans < tmp) {
              ans = tmp;
            }
            tmp = 0;
        }
    }
    std::cout << ans << std::endl;
    return 0;
}