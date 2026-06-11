#include <bits/stdc++.h>
using namespace std;

int main(void){

    string s;
    int N;
    cin >> N >> s;

    int count = 1;
    char now_s = s[0];
    
    for(int i=1;i<N;i++){
        if(s[i] != now_s){
            now_s = s[i];
            count++;
        }
    }
    cout << count << endl;
}
