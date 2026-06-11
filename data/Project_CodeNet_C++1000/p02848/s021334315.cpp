
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
const ll INF = 1LL << 60;

string alpha="ABCEDFGHIJKLMNOPQRSTUVWXXY";

int main(){
    int n;
    string s;
    cin >> n >> s;
    for(int i=0; i<s.size(); i++){
        //Zを超える=90を超える
        //char+intをすることでで数値に変換される
        if(s[i]+n>90){
            cout << char(64+(s[i]+n)%90);
        }
        else{
            cout << char(s[i]+n);
        }
    }
}