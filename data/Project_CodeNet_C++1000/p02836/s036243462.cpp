#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
using P = pair<int,int>;

int main(){
    string s;
    cin >> s;
    int n = s.size();
    int count = 0;
    if(n%2 == 0){
        for(int i = 0; i < n/2; i++){
            if(s[i] != s[n - 1 - i]) count++;
        }
    }
    else{
        for(int i = 0; i < (n - 1)/2; i++){
            if(s[i] != s[n - 1 - i]) count++;
        }
    }
    cout << count << endl;
    return 0;
}