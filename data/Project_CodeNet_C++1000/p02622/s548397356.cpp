#include <iostream>
#include <iomanip>
#include <string>
#include <algorithm>
#include <vector>
#include <cmath>
#include <vector>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define rep2(i,s,n) for(int i = (s);i<(int)(n);i++)

int main(){
    string s,t;
    cin >> s >> t;
    int k = s.size();
    int sum = 0;
    rep(i,k)if(s[i] != t[i])sum++;
    cout << sum << endl;
}