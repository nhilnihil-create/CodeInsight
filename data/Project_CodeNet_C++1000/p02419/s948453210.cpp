#include<iostream>
using namespace std;
#include<string>
#include<algorithm>

int main() {
        string str, str2;
        int r, i;
        r = 0;
        cin >> str;
        transform(str.begin(), str.end(), str.begin(), ::tolower);
        for(i = 0; i < 1000; i++) {
                cin >> str2;
                if (str2 == "END_OF_TEXT") break;
                transform(str2.begin(), str2.end(), str2.begin(), ::tolower);
                if( str == str2 ) {
                        r++;
                }
        }
        cout << r << endl;
        return 0;
}