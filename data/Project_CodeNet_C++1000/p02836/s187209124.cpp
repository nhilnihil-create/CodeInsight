#include<bits/stdc++.h>
#include <algorithm>
#define rep(i,n) for (int i=0;i<(n);i++)
#define PI 3.14159265358979323846264338327950L
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
int main(void){
    string s;
    cin >> s;
    int size = s.length();
    int cnt = 0;
    int j = 0;
    for(int i = size-1; i>=size/2 ;--i){
        if(s[j] != s[i]){
            cnt++;
        }
        j++;
    }
    cout << cnt << endl;
}