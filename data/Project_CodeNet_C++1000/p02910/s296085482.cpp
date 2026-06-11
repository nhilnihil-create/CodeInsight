#include <iostream>
#include <algorithm>
#include <math.h> 
#include <string>
#include <iomanip>
#include <vector>
#include <chrono>
#include <cstdlib>
#include <bitset>
using namespace std;
int main(){
    string s;
    cin >> s;
    int l = s.length();
    int counta = 0;
    int countb = 0;
    for(int i = 0; i < l; i++){
        if(i%2 == 0){
            if(s[i] != 'L') counta++;
        }
        else if(i%2 != 0){
            if(s[i] != 'R') countb++;
        }
    }
    //cout << counta << " " << countb << " " << l << endl;
    if(counta + countb == l) cout << "Yes" << endl;
    else cout << "No" << endl;
}