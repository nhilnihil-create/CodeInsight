#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;

string hash[9999999] = {};

int h1(int key, int m) {
    return key % m;
}
int h2(int key, int m) {
    return 1 + (key % (m - 1));
}
int h(int key, int i, int m) {
    return (h1(key, m) + i * h2(key, m)) % m;
}

int getChar(char ch) {
    if (ch == 'A') return 1;
    else if (ch == 'C') return 2;
    else if (ch == 'G') return 3;
    else if (ch == 'T') return 4;
    else return 0;
}

long long getKey(string str) {
    long long sum = 0, p = 1;
    int size = str.size();
    for (int i = 0; i < size; i++) {
        sum += p * getChar(str[i]);
        p *= 5;
    }

    return sum;
}
        
int main() {
    int count;
    bool b[1000000];

    cin >> count;
    for (int i = 0; i < count; i++) {
        string command, value;
        cin >> command >> value;

        long long key = getKey(value);
        if (command == "insert") {
            int j = 0;
            while (true) {
                int k = h(key, j, 9999999);
                if ((hash[k] == value) || (hash[k].size() == 0)) {
                    hash[k] = value;
                    break;
                }
       //cout << "hai " << j << " " << k << " " << hash[k] << endl;

                j++;
            }
        }
        else {
            int j = 0;
            while (true) {
                int k = h(key, j, 9999999);
                if (hash[k] == value) {
                    printf("yes\n");
                    break;
                } else if (hash[k].size() == 0 || k >= count) {
                    printf("no\n");
                    break;
                }
                j++;
            }
        }
    }
}