#include <iostream>
#include <string>
#include <cstdio>

using namespace std;

int main() {
    // string str;
    char str;
    // cin >> str;
    int Alpha[26] = {0};
    while((str = getchar()) != EOF) {
        // for(int i = 0; i < str.length(); i++) {
        // if(str[i] >= 'A' && str[i] <= 'Z') {
        //     Alpha[str[i]-'A']++;
        // }
        // if(str[i] >= 'a' && str[i] <= 'z') {
        //     Alpha[str[i]-'a']++;
        // }
        // }
        if(str >= 'A' && str <= 'Z') Alpha[str-'A']++;
        if(str >= 'a' && str <= 'z') Alpha[str - 'a']++;
    }
    char alpha = 'a';
    for(int i = 0; i < 26; i++) {
        cout << alpha << " : " << Alpha[i] << endl;
        alpha++;
    }
    // getline(cin, str);
    return 0;
}
