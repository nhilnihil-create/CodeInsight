#include<bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef pair<int, int> P;

int main(){
    string s;
    cin >> s;
    if(s == "Sunny"){
        cout << "Cloudy" << endl;
    }else if(s == "Cloudy"){
        cout << "Rainy" << endl;
    }else{
        cout << "Sunny" << endl;
    }
}