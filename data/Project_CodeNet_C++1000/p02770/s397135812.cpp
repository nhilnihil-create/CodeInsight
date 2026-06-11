#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int divceil(int a, int b){
    return (a+b-1)/b;
}

int main(){
    long long k, q;
    cin >> k >>q;

    vector<long long> d(k);
    for(int i=0; i<k; ++i) cin >> d[i];

    for(int _=0; _<q; ++_){
        int n, x , m;
        cin >> n >> x >> m;
        //最後の項
        long long last = x;
        //0が何個なのか
        long long eq = 0;
        //diが何回たされるか
        for(int i=0; i<k; ++i){
            long long num = divceil(n-1-i, k);
            last += (d[i]%m)*num;
            if(d[i]%m == 0) eq += num;
        }
        //答え 全体 - (>)
        long long ans = (n-1) - (last/m -x/m);
        //イコールの場合も引く
        ans -= eq;
        cout << ans << endl;
    }
    return 0;
}
