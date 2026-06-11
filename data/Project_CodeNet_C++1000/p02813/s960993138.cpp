#include <bits/stdc++.h>

using namespace std;
using ll = long long;

//cout << std::fixed << std::setprecision(15) << y << endl;

int main() {
    int n = 0;
    cin >> n;
    string x;
    for(int i = 0;i < n;i++){
        x += i + 1 + '0';
    }
    string sp;
    string sq;
    for(int i = 0;i < n;i++){
        int tmpP = 0;
        cin >> tmpP;
        sp += tmpP + '0';
    }
    for(int i = 0;i < n;i++){
        int tmpQ = 0;
        cin >> tmpQ;
        sq += tmpQ + '0';
    }
    int p,q = 0;
    p = stoi(sp);
    q = stoi(sq);
    int a = 0;
    int b = 0;
    int cnt = 0;
    do{
        int tmp = 0;
        tmp = stoi(x);
        if(tmp == p){
            a = cnt;
        }
        if(tmp == q){
            b = cnt;
        }
        cnt ++;
    }while(next_permutation(x.begin(),x.end()));
    cout << abs(a - b) << endl;

    return 0;
}