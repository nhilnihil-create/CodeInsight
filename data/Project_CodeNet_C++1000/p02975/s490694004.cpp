// a_2 = a_1 xor a_3 = (a_0 xor a_2) xor a_3
// このことから、 a_0 xor a_3 = 0 つまり a_0 = a_3であることがわかる。
// N == 3*k (k = 1,2,3,...)のとき、
// {a_i}が3つの数から成り、b_0, b_1, b_2として、b_0 xor b_1 = b_2が成り立つか判定
// N % 3 != 0 なら、全ての数が等しくなるか(0になる)どうか判定
#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    if(N % 3) {
        int a;
        cin >> a;
        if(a != 0) { cout << "No" << endl; return 0; }
        for(int i = 1; i < N; ++i) {
            int tmp;
            cin >> tmp;
            if(a != tmp) { cout << "No" << endl; return 0;}
        }
        cout << "Yes" << endl;
        return 0;
    }

    map<int,int> Map;
    for(int i = 0; i < N; ++i) {
        int a;
        cin >> a;
        ++Map[a];
    }
    vector<int> B, Num;
    for(auto &p : Map) {
        B.push_back(p.first);
        Num.push_back(p.second);
    }
    /*
    for(int i = 0; i < Num.size(); ++i) {
        cout << "B: " << B[i] << " Num: " << Num[i] << endl;
    }
    */
    if(Num.size() > 3) { cout << "No" << endl; return 0; }
    if(Num.size() == 3) {
        if(Num[0] != Num[1] || Num[1] != Num[2] || Num[2] != Num[0]) { cout << "No" << endl; return 0;}
        //cout << B[0] << " xor " << B[1] << " = " << (B[0] ^ B[1]) << endl;
        if((B[0] ^ B[1]) == B[2]) cout << "Yes" << endl;
        else cout << "No" << endl;
        return 0;
    }
    if(Num.size() == 2) {
        if(Num[0] > Num[1]) { swap(Num[0], Num[1]); swap(B[0], B[1]); }
        if(B[0] != 0) { cout << "No" << endl; return 0; }
        if(Num[0] * 2 == Num[1]) { cout << "Yes" << endl; }
        else cout << "No" << endl;
        return 0;
    }
    if(Num.size() == 1) {
        if(B[0] == 0) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    return 0;
}