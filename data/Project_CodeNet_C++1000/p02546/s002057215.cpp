#include <bits/stdc++.h>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;


string moji;


int main(){

    cin >>moji;
    int isize = moji.size();

    if(moji[isize -1 ] == 's')
    {
        cout << moji + "es";
    }else
    {
        cout << moji + 's';
    }

    return  0;
}
