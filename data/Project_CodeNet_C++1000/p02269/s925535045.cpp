#include <string.h>
#include <iostream>

using namespace std;

const int M = 1000003;
const int L = 12;

char dict[M][L];


int h1(long key) {
    return key % M;
} 

int h2(long key) {
    return 1 + key % (M - 1);
}

int h(long key, int i) {
    return (h1(key) + i * h2(key)) % M;
}

long strToKey(char str[]) {
    long result = 0;

    int length = strlen(str);
    for (int i = 0; i < length; i++) {
        // Because there is only 4 kind of letters
        result *= 5;
        switch(str[i]) {
            case 'A':
                result += 1;
                break;
            case 'C':
                result += 2;
                break;
            case 'G':
                result += 3;
                break;
            case 'T':
                result += 4;
                break;
        }
    }
    
    return result;
}

int insert(char str[]) {
    long key = strToKey(str);

    int i = 0;
    int index = h(key, i);
    while (dict[index][0] != '\0') {
        i += 1;
        index = h(key, i);
    }
    strcpy(dict[index], str);
    return 0;
}

int find(char str[]) {
    long key = strToKey(str);

    int i = 0;
    int index = h(key, i);
    while (dict[index][0] != '\0') {
        if(strcmp(dict[index], str) == 0) {
            return index;
        } else {
            i += 1;
            index = h(key, i);
        }
    }
    return -1;
}


int main() {
    for (int i = 0; i < M; i++) {
        dict[M][0] = '\0';
    } 
    
    int n;
    cin >> n;
    char cmd[6];
    char str[L];
    for (int i = 0; i < n; i++) {
        cin >> cmd >> str;
        switch(cmd[0]) {
            case 'i':
                insert(str);
                break;
            case 'f':
                if(find(str) >= 0) {
                    cout << "yes\n";
                } else {
                    cout << "no\n";
                }
                break;
        }
    }
}
