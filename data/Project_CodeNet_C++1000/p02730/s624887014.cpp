#include <bits/stdc++.h>
using namespace std;
int main(void){

    string s;
    cin >> s ;
    int cnt = 0;
    
    for(int i = 0; i < s.size() / 4 + 1; i++){
        //printf("%d %lu %c %c\n", i, ( s.size() - 3 ) / 2 - i, s.at(i), s.at(( s.size() - 3 ) / 2 - i));
        if(s.at(i) != s.at(( s.size() - 3 ) / 2 - i)){
            cnt++;
        }
        //printf("%d %lu %c %c\n", s.size() - 1 - i, ( s.size() + 1 ) / 2 + i, s.at(s.size() - 1 - i), s.at(( s.size() + 1 ) / 2 + i));
        if(s.at(s.size() - 1 - i) != s.at(( s.size() + 1 ) / 2 + i)){
            cnt++;
        }
        //printf("%d %lu %c %c\n", i, s.size() - 1 - i, s.at(i), s.at(s.size() - 1 - i));
        if(s.at(i) != s.at(s.size() - 1 - i)){
            cnt++;
        }
    }

    if(cnt == 0){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

}
