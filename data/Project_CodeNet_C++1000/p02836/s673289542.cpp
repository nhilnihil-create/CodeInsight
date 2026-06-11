#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef long long ll;
#define rep1(i, n) for(int i = 1; i <=(ll)(n); i++)
#define rep0(i, n) for(int i = 0; i <=(ll)(n); i++)

int main(){
    string s, s_original;
    cin >> s;
    int min_count = 0;
    int count_diff = 0;
    s_original = s;
    reverse(s.begin(), s.end());
    string s_reverse = s;
    rep0(i,s_original.size()-1){
        if(s_reverse[i] != s_original[i]) count_diff++;
    }
    if(count_diff % 2 == 0){
        min_count = count_diff/2;
    }else{
        min_count = (count_diff-1)/2;
    }
    cout << min_count << endl;
    return 0;
}