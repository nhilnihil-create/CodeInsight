#include <bits/stdc++.h>
using namespace std;
int main() {

     string s;
     cin >> s;


     int n;

    if(s == "SUN")
        n = 7;
    else if(s == "MON")
        n = 6;
    else if(s == "TUE")
        n = 5;
    else if(s == "WED")
        n = 4;
    else if(s == "THU")
        n = 3;
    else if(s == "FRI")
        n = 2;
    else if(s == "SAT")
        n = 1;


    cout<<n<<endl;



    return 0;
}
