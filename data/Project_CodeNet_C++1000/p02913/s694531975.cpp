#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    string s; cin >> s;
    int l = 0;
    int r = N / 2 + 1;
    while(r-l > 1){
        int mid = (l+r)/2;
        bool ok = false;
        vector<string> sub;
        for (int i = 0; i < N-mid+1; i++){
            string now = s.substr(i, mid);
            sub.push_back(now);
        }

        for (int i = 0; i < N-mid; i++){
            for (int j = i+mid; j < N-mid+1; j++){ 
                if(sub[i] == sub[j]){
                    ok = true;
                    break;
                }
            }
            if(ok)break;
        }
        if(ok){
            l = mid;
        } else {
            r = mid;
        }
    }

    cout << l << endl;

    return 0;
}