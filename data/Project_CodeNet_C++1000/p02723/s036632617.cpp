#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <map>
#define rep(i, n)   for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main(){
    string s;   cin>>s;
    if(s[2] == s[3] && s[4] == s[5]){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
