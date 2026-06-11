#include <iostream>
#include <string>
using namespace std;

void myReplace(int be, int en, string& src) {
    string replacement;
    cin >> replacement;

    src.erase(be, en - be + 1);
    src.insert(be, replacement);
}

void myReverse(int be, int en, string& src) {
    int i = be, j = en;
    while (1) {
        if (i >= j) {return;}
        src[i] = src[i] ^ src[j];
        src[j] = src[i] ^ src[j];
        src[i] = src[i] ^ src[j];
        ++i;
        --j;
    }
}

void myPrint(int be, int en, string& src) {
    string tmp = "";
    tmp.assign(src, be, en - be + 1);

    cout << tmp << endl;
}

int main() {
//    freopen("in.txt", "r", stdin);

    int q, be, en;
    string op, src, p;

    cin >> src >> q;
    for (int i = 0; i < q; ++i) {
        cin >> op >> be >> en;

        if (op == "replace") {myReplace(be, en, src);}
        else if (op == "reverse") {myReverse(be, en, src);}
        else if (op == "print") {myPrint(be, en, src);}
    }
}