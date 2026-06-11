#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void)
{
    int N;
    string S;
    cin >> N >> S;

    int ans = 0;
    
    for (int i = 0; i < 1000; i++)
    {
        int d1 = i/100;
        int d2 = (i%100)/10;
        int d3 = i%10;

        int sel = 0;
        for (int i = 0; i < N; i++)
        {
            if(sel == 0){
                if(d1 == (S[i] - '0')) sel++;
            } else if(sel == 1){
                if(d2 == (S[i] - '0')) sel++;
            } else if(sel == 2){
                if(d3 == (S[i] - '0')) sel++;
            } else if(sel == 3){
                break;
            }
        }

        if(sel == 3) {
            ans++;
        }
    }

    cout << ans << endl;
    
    return 0;
}
