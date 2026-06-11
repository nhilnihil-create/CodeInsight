#include <bits/stdc++.h>
using namespace std;

int main(){
    int n, k, r, s, p;
    string t;
    cin >> n >> k >> r >> s >> p >> t;

    int ans = 0;
    for(int i=0; i<k; i++){
        int j = i;
        int count = 0;
        while(j < n){
            if(j - k >= 0 && t[j] == t[j-k]) count += 1;
            else count = 0;

            if(count % 2 == 0){
                if(t[j] == 'r') ans += p;
                if(t[j] == 's') ans += r;
                if(t[j] == 'p') ans += s;
            }
            j += k;
        }
    }
    cout << ans << endl;
    return 0;
}