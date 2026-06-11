#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    long long K;
    cin >> K;
    long long ans = 0;
    int t = 1;
    int flag = 0;
    int nb = 0;
    int ne = 0;
    int count = 0;
    for(int i = 1; i < s.size(); i++){
        if(s[i - 1] == s[i]) t++;
        else{
            count += t / 2;
            if(flag == 0){
                nb = t;
                flag = 1;
            }
            t = 1;
        }
        if(i == s.size() - 1) ne = t;
    }
    count -= nb / 2;
    if(s[0] == s[s.size() - 1] && flag != 0){
        ans += count*K + (nb + ne) / 2 * (K - 1) + nb / 2 + ne / 2; 
    }
    else if(s[0] == s[s.size() - 1] && flag == 0){
        ans += s.size()*K / 2;
    }
    else{
        ans += (count + nb / 2 + ne / 2) * K;
    }
    cout << ans << endl;
}