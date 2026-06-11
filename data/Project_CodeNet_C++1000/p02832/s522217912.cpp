#include <bits/stdc++.h>
#define rep(i,n) for(int i=0; i<n; i++)
#define rrep(i,n) for(int i=1; i<n; i++)
using namespace std;
using vi = vector<int>;
//ABC148_D
int main(){
    int n, count=0;
    cin >> n;
    vi ai(n);
    rep(i,n){
        cin >> ai.at(i); 
    }
    int j=0;
    rep(i,n){
        if (ai.at(i) == 0){
            continue;
        }
        else if (ai.at(i) != i+j+1){
            ai.at(i) = 0;
            j -= 1;
            count += 1;
        }

    }
    sort(ai.begin(), ai.end());
    if (ai.at(n-1) == 0)cout << -1 << '\n';
    else cout << count << '\n';
    return 0;
    

}