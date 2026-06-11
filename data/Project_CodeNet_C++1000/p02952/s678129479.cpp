#include<bits/stdc++.h>
#define rep(i,n) for (int i=0;i<(n);i++)
#define PI 3.14159265358979323846264338327950L
using namespace std;
using P = pair<int,int>;
using ll = long long;
using namespace std;
int main(void){
    int n;
    cin >> n;
    string str;
    int cnt = 0;
    for(int i = 1; i <= n; ++i){
        str = to_string(i);
        if(str.size() % 2 == 1){
            ++cnt; 
        }
    }
    
    cout << cnt << endl;
}