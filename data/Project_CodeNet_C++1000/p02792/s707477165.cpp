#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;cin >> N;
    map<int, int> mp;
    for (int i = 1; i <= N; i++)
    {
        int j = i, a = i%10, b;
        while(j > 0){
            b = j;
            j /= 10;
        }
        mp[10*b+a]++;
        // string i_str = to_string(i);
        // int s = i_str.size();
        // pair<int, int> p = make_pair((int)i_str[0], (int)i_str[s-1]);
        // mp[p]++;
    }

    int64_t ans = 0;
    for (int i = 1; i <= 9; i++) for (int j = 1; j <= 9; j++) ans += mp[10*i+j]*mp[10*j+i];
    // int keta = 0, ichi = N % 10, sup;
    // int temp = N;
    // while(temp > 0){
    //     keta++;
    //     sup = temp;
    //     temp /= 10;
    // }
    
    cout << ans << endl;
    return 0;
}