#define _GLIBCXX_DEBUG
#include <iostream>
#include <vector>
#include <string>
using namespace std;
using vi = vector<int>;
using vc = vector<char>;

int main(void){
    int n, m;
    cin >> n >>m;
    vi S(m);
    vc C(m);
    for(int i=0; i<m; i++) cin >> S[i] >> C[i];
    int begin, end;
    switch(n){
        case 1: begin = 0; end = 10; break;
        case 2: begin = 10; end = 100; break;
        case 3: begin = 100; end = 1000; break;
    }
    for(int i=begin; i<end; i++){
        string str = to_string(i);
        bool ok = true;
        for(int j=0; j<m; j++)if(str[S[j]-1] != C[j]) ok = false;
        if(ok){ cout << i << '\n'; return 0; }
    }
    cout << -1 << '\n';
    return 0;
}