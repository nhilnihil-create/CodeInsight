#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,a,b,c,d;
    int space = 0,stone = 0,max_sp = 0,max_st = 0;
    string s;

    cin >> n >> a >> b >> c >> d >> s;

    for(int i = b - 2;i <= d;i++){
       if(s[i] == '.')space++;
       else {
           max_sp = max(max_sp,space);
           space = 0;
       }
    }
    max_sp = max(max_sp,space);

     for(int i = a - 1;i < max(c,d);i++){
       if(s[i] == '#')stone++;
       else {
           max_st = max(max_st,stone);
           stone = 0;
       }
    }
    max_st = max(max_st,stone);

    if(d < c && max_sp <= 2 ||max_st >= 2)cout << "No" << endl;
    else cout << "Yes" << endl;

}
