#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
void p(vector<char> A){rep(i,A.size()){cout << A[i];}cout << endl;}

int main(){
    int n;
    cin >> n;
    vector<int> h(n);
    rep(i,n) cin >> h[i];
    int now = h[0];
    for(int i = 1;i < n;i++){
        if (h[i] >= now){
            now = h[i];
        }
        else if (now - h[i] == 1){
            now = h[i] + 1;
        }
        else{
            cout << "No";
            exit(0);
        }
        //cout << now << endl;
    }
    cout << "Yes";
}