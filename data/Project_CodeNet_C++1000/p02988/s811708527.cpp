#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;

int main(){
    int n;
    cin >> n;
    vector<int> in(n);
    rep(i,n) cin >> in.at(i);
    int count = 0;
    rep(i,n - 2){
        if(in.at(i) < in.at(i + 1) && in.at(i + 1) < in.at(i + 2)) count++;
        else if(in.at(i) > in.at(i + 1) && in.at(i + 1) > in.at(i + 2)) count++;
    }
    cout << count << endl;
}
