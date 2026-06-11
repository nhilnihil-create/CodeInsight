#include <bits/stdc++.h>

#define F first
#define S second
#define int long long
#define inf 1000000000

using namespace std;

vector<int> lunlun;

int k;

void prnt(){
    cout << lunlun[k-1] << endl;
    exit(0);
}

void nxt(const int& len, const int& frst, int prv){
    prv = prv*10+frst;
    if (len == 1){
        lunlun.push_back(prv);
        if ((int)lunlun.size() == k){
            prnt();
        }
        return;
    }
    if (frst > 0){
        nxt(len-1, frst-1, prv);
    }
    nxt(len-1, frst, prv);
    if (frst < 9){
        nxt(len-1, frst+1, prv);
    }
}

signed main(){
    cin >> k;
    for (int ln = 1; ln < 11; ln++){
        for (int fr = 1; fr < 10; fr++){
            nxt(ln, fr, 0);
        }
    }
    //cout << (int)lunlun.size() << endl;
    return 0;
}





















