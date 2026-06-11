#include <iostream>
#include <string>
#include <stdio.h>
#include <cmath>
#include <cfloat>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iterator>
#include <set>
#include <map>
using namespace std;

const double PI=acos(-1);

int main(){
    string s;
    cin >> s;
    int cnt = 0;
    char prev = ' ';
    for(int i = 0; i < s.length(); i++){
        int j = i;
        if(i == 0){
            cnt++;
            prev = s[i];
            continue;
        }
        if(i == s.length()-1){
            if(prev != s[i]) cnt++;
            continue;
        }
        if(prev == s[i]){
            cnt++;
            i++;
            prev = ' ';
        }else{
            cnt++;
            prev = s[i];
        }
    }
    cout << cnt << endl;
    return 0;
}