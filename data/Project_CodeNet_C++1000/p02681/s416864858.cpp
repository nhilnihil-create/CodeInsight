#include <bits/stdc++.h>

using namespace std;


int main(){
    string a,b;
    cin >> a >> b;
    smatch smatch;
    if(regex_search(b,smatch,regex(a+'.'))){
        puts("Yes");
    }else puts("No");
    return 0;
}