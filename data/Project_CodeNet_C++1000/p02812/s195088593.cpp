#include <iostream>
#include <vector>
#include <math.h>

using namespace std;

int main() {
    int n;
    string s;
    cin >> n;
    cin >> s;
    int i = 0;
    int count = 0;
    while(i < n){
        if(s[i] == 'A'){
            i++;
            if(s[i] == 'B'){
                i++;
                if(s[i] == 'C'){
                    count++;
                    i++;
                }
            }
        }else{
            i++;
        }
    }
    cout << count << endl;
    return 0;
}

