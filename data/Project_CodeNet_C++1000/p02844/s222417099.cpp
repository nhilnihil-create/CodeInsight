#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    long long n;
    cin >> n;
    string s;
    cin >> s;
    
    long long count = 0;
    for(char i = '0'; i <= '9'; i++){
        if(s.find(i) == string::npos){
            continue;
        }
        string s1 = s.substr(s.find(i)+1);
        for(char j = '0'; j <= '9'; j++){
            if(s1.find(j) == string::npos){
                continue;
            }
            string s2 = s1.substr(s1.find(j)+1);
            for(char k = '0'; k <= '9'; k++){
                if(s2.find(k) == string::npos){
                    continue;
                }
                count++;
            }
        }
    }

    cout << count << endl;

    return 0;
}