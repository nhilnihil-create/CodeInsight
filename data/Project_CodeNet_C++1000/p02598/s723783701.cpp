#include <bits/stdc++.h>
using namespace std;

const int maxN = 2e5+5;
int A[maxN];
int n, k;

bool check(int cut){
    int curr = k;
    for(int i = 0; i < n; i++){
        curr -= A[i]/cut;
        if(A[i] % cut == 0) curr++;
        if(curr < 0) return false;
    }
    return true;
}

void solve(){
    cin >> n >> k;
    for(int i = 0; i < n; i++)
        cin >> A[i];
    int p = 1, q = (*(max_element(A, A+n)));
    while(p != q){
        int m = (p+q)/2;
        if(check(m))
            q = m;
        else
            p = m+1;
    }
    cout << p << "\n";
}


int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);

    bool multitest = false;
    //multitest = true;
    if(multitest){
        int t; cin >> t;
        while(t--)
            solve();
    }
    else
        solve();
}




