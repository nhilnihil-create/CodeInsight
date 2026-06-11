#include <iostream>
#include <algorithm>
#include <string>
#define ll long long
using namespace std;
int main(){
 string s;
 string t;
 ll cou=0;
 cin>>s>>t;
    for (ll i = 0; i <s.size() ; ++i) {
        if(s[i]==t[i]){ continue; }
        else{
          cou++;
        }
    }
    cout<<cou;
}