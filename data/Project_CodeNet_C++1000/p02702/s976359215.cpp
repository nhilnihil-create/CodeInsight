#include<bits/stdc++.h>
using namespace std;
#define N 2000005
int main(){
    string s;
    cin >> s;
    const int p = 2019;
    long ans = 0;
    int l = s.size();
    vector<int> list(N), mod(N);
    list[0] = 1;
    mod[0] = (s.at(l - 1) - '0') % p;
    for(int i = 1; i < l; i++){
        list[i] = (list[i - 1] * 10) % p;
        mod[i] = ((s.at(l - i - 1) - '0') * list[i] + mod[i - 1]) % p;
    }
    for(int i = 0; i < p; i++)
        list[i] = 0;
    for(int i = 0; i < l; i++){
        if(mod[i] == 0)
            ans ++;
        ans += list[mod[i]];
        list[mod[i]] ++;
    }
    cout << ans << endl;
    return 0;
}