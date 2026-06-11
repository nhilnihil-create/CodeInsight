/*
      author : nishi5451
      created: 11.08.2020 22:20:27
*/

#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
typedef long long ll;


int main(){
    string s;
    cin >> s;
    if(s=="Sunny") cout << "Cloudy" << endl;
    else if(s=="Cloudy") cout << "Rainy" << endl;
    else if(s=="Rainy") cout << "Sunny" << endl;
    return 0;
}