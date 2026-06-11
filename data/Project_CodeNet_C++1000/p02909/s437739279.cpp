#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define pii pair<int , int>
#define _FastIO ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0)
#define MAXX 1005

string s;

int main()
{
    _FastIO;
    cin >> s;
    string a[4] = {"Sunny" , "Cloudy" , "Rainy" , "Sunny"};
    for(int i = 1; i < 4; i++){
        if(a[i - 1] == s){
            cout << a[i] << endl;
            return 0;
        }
    }
    return 0;
}
