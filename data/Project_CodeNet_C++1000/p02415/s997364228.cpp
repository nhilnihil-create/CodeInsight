#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int main() {
    char str[1201];
    
    fgets(str, sizeof(str), stdin);
    
    for (int i = 0; i < strlen(str); i++){
        if (str[i] >= 97 && str[i] <= 122)
            str[i] -= 32;
        else if (str[i] >= 65 && str[i] <= 92)
            str[i] += 32;
    }
    cout << str;
    return 0;
}
