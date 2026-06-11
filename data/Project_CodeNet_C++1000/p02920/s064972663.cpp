#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int lol[1<<18] = {};
int oof[19] = {};
int uwu[19] = {};
int sum = 0, n, m;
vector<int> vec;

void update(int s){
    int i = n, j, t = s;
    while (t){
        j = uwu[i];
        if (j < t){
            t -= j;
            uwu[i] = 0;
            sum -= j;
            oof[i] = j;
        }
        else{
            uwu[i] -= t;
            sum -= t;
            oof[i] = t;
            t = 0;
        }
        i--;
    }
    t = s;
    for (int i = 0; i <= n; i++){
        t -= oof[i];
        oof[i] = 0;
        uwu[i] += t;
        sum += t;
    }
}


int main(){
    ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);

    cin >> n;
    m = 1<<n;
    for(int i = 0; i < m; i++) cin >> lol[i];
    sort(lol, lol + m);

    int i = m - 1, s = 1;
    while (i){
        if (lol[i] == lol[i-1]) s++;
        else{
            vec.push_back(s);
            s = 1;
        }
        i--;
    }
    vec.push_back(s);

    uwu[n] = 1;
    sum = 1;
    bool ans = 1;

    for (int i = 0; i < vec.size(); i++){
        s = vec[i];
        if (sum < s){
            ans = 0;
            break;
        }
        else{
            update(s);
        }
    }
    if (ans) cout << "Yes\n";
    else cout << "No\n";
}
