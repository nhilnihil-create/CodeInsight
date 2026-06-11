#include <bits/stdc++.h>

using namespace std;

int main() {
    string str1;
    cin >> str1;
    string str2;
    cin >> str2;

    bool correct = true;

    if (str2.length()-str1.length()!=1){
        correct = false;
    }

    if (correct){
        for(int i=0; i<str1.length(); i++){
            if (str1.at(i)!=str2.at(i)){
                correct = false;
            }
        }
    }

    if (correct) {printf("Yes\n");}
    else {printf("No\n");}
    return 0;
}
