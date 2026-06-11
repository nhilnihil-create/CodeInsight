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
    string n;
    cin >> n;
    int k = 0;
    int l = n.size();
    rep(i,l){
        int m = n[i] - '0';
        k += m;
    }
    if(k%9 == 0)cout << "Yes" << endl;
    else cout << "No" << endl;
}