#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(void) {
    string str;
    vector<string> v;
    while (getline(cin, str)) {
        v.push_back(str);
    }

    for (vector<string>::iterator itr = v.begin(); itr != v.end(); itr++) {
        int a, b;
        sscanf((*itr).c_str(), "%d %d", &a, &b);

        int sum = a + b;

        int c = 1;
        int d = 10;
        int z = sum / d;

        while (z != 0) {
            d = d * 10;
            z = sum / d;
            c++;
        }
        printf("%d\n", c);
    }
    return 0;
}