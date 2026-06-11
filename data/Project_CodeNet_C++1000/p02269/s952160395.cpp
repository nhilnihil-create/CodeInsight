#include <iostream>
#include <string>

using namespace std;

const int M = 1046527;
string table[M];

int get_char(char c) {
    if (c == 'A') return 1;
    else if (c == 'C') return 2;
    else if (c == 'G') return 3;
    else if (c == 'T') return 4;
    else return 0;
}

long long get_key(string &text) {
    long long sum = 0, p = 1;
    for (auto &e : text) {
        sum += p * get_char(e);
        p *= 5;    // 5 ** (text.size())
    }
    return sum;
}

int h1(int k) {
    return k % M;
}

int h2(int k) {
    return 1 + (k % (M-1));
}

bool insert(string &text) {
    int i = 0;
    long long k = get_key(text);
    while (true) {
        long long j = (h1(k) + i * h2(k)) % M; 
        if (table[j] == text) return true;
        else if (table[j].empty()) { table[j] = text; return false; }
        else i += 1;
    }
    return false;
}

bool find(string &text) {
    int i = 0;
    long long k = get_key(text);
    while (true) {
        long long j = (h1(k) + i * h2(k)) % M;
        if (table[j] == text) return true;
        else if (table[j].empty()) return false;
        else i += 1;
    }
    return false;
}

int
main(int argc, const char *argv[])
{
    int n;
    cin >> n;
    while (n--) {
        string order, text;
        cin >> order >> text;
        if (order[0] == 'i') {
            insert(text);
        } else {
            if (find(text)) cout << "yes";
            else cout << "no";
            cout << endl;
        }
    }

    return 0;
}