#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main(){
    int n, k, r, s, p;
    cin >> n >> k;
    cin >> r >> s >> p;
    string t;
    cin >> t;
    int ans = 0;
    char u[n];
    for(int i = 0; i < n; i++){
        if(i < k){
            if(t.at(i) == 'r'){
                ans += p;
                u[i] = 'p';
            }
            else if(t.at(i) == 's'){
                ans += r;
                u[i] = 'r';
            }
            else{
                ans += s;
                u[i] = 's';
            }
        }
        else{
            if(t.at(i) == 'r'){
                if(u[i - k] == 'p')
                    u[i] = '1';
                else{
                    u[i] = 'p';
                    ans += p;
                }
            }
            else if(t.at(i) == 's'){
                if(u[i - k] == 'r')
                    u[i] = '1';
                else{
                    u[i] = 'r';
                    ans += r;
                }
            }
            else{
                if(u[i - k] == 's')
                    u[i] = '1';
                else{
                    ans += s;
                    u[i] = 's';
                }
            }
        }
    }
    cout << ans << endl;
    return 0;
}