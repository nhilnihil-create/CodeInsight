#include <bits/stdc++.h>
using namespace std;

int main(){
    char s[4];
    scanf("%s", s);
    map <char, int> freq;
    for(int i = 0; i < 4; i++){
        freq[s[i]]++;
        if(freq[s[i]] >= 3)
            return puts("No"), 0;
    }
    for(auto x : freq){
        if(x.second != 2)
            return puts("No"), 0;
    }
    puts("Yes");
    return 0;
}
