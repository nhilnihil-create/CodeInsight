#include <bits/stdc++.h>
#include <string>
using namespace std;

int main() {
    string w_record;
    cin >> w_record;
    int count=0;
    for (int i=0; i<3; i++) {
        char day = w_record[i];
        if (day == 'R') {
            count++;
        }
    }
    char second_day = w_record[1];
    if (count == 2 && second_day == 'S') {
        count = 1;
    }
    cout << count << endl;
}