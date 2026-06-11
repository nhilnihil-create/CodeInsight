#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
#include <map>
#include <string>

#define reps(i,s,n) for(int (i) = (s); (i) < (n); (i)++)
#define rep(i,n) reps(i,0,n)
using namespace std;
using ll = long long;

int main(){
    string str = "abcdefghijklmnopqrstuvwxyz";
    string str2;
    cin >> str2;
    int a = str2[0] - 'a';
    cout << str[a+1] << endl;

    return 0;
}