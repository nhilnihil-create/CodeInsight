#include <iostream>
#include <vector>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::string;

struct Four_digit {
    string s1;
    string s2;
    int m;
    int c;
    int x;
    int i;
};

vector<int> rewrite (string str); 
void sum(vector<int> &v1, vector<int> &v2); 
void output (vector<int> number); 

int main(void) {
    int n;
    cin >> n;
    vector<int> s1;
    vector<int> s2;
    for (int i = 0; i < n; i++) {
        Four_digit num;
        cin >> num.s1 >> num.s2;
        s1 = rewrite(num.s1);
        s2 = rewrite(num.s2);
        sum(s1, s2);
        output(s1);
    }
    return 0;
}

vector<int> rewrite (string str) {
    vector<int> number(4, 0);

    if (str[0] == 'm') {
        number[0] = 1;
    } else if (str[0] == 'c') {
        number[1] = 1;
    } else if (str[0] == 'x') {
        number[2] = 1;
    } else if (str[0] == 'i') {
        number[3] = 1;
    }

    for (int i = 1; i < str.length(); i++) {
        if (str[i] == 'm') {
            if (str[i - 1] >= '0' && str[i - 1] <= '9') {
                number[0] = str[i - 1] - '0';
            } else {
                number[0] = 1;
            }
        } else if (str[i] == 'c') {
            if (str[i - 1] >= '0' && str[i - 1] <= '9') {
                number[1] = str[i - 1] - '0';
            } else {
                number[1] = 1;
            }
        } else if (str[i] == 'x') {
            if (str[i - 1] >= '0' && str[i - 1] <= '9') {
                number[2] = str[i - 1] - '0';
            } else {
                number[2] = 1;
            }
        } else if (str[i] == 'i') {
            if (str[i - 1] >= '0' && str[i - 1] <= '9') {
                number[3] = str[i - 1] - '0';
            } else {
                number[3] = 1;
            }
        }
    }
    return number; 
}

void sum(vector<int> &v1, vector<int> &v2) {
    for (int i = 0; i < v1.size(); i++) {
        v1[i] += v2[i];
    }
    for (int i = 3; i > 0; i--) {
        if (v1[i] >= 10) {
            v1[i] -= 10; 
            v1[i - 1]++;
        }
    }
    return;
}

void output (vector<int> v) {
    char kigou[4] = {'m', 'c', 'x', 'i'};
    for (int i = 0; i < 4; i++) {
        if (v[i] == 0) {
            continue; 
        } else if (v[i] == 1) {
            cout << kigou[i];
        } else {
            cout << v[i] << kigou[i];
        }
    }
    cout << endl;
    return;
}