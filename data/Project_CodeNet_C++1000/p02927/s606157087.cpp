#pragma GCC optimize("Ofast")
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<math.h>
#include<utility>
using namespace std;


int main(){
    int m, d;
    cin >> m >> d;

    int res = 0;
    int d1;
    int d2;

    for(int month=4;month<=m;month++){
        for(int day=22;day<=d;day++){
            int tmp = day;
            d1 = day % 10;
            if(d1 < 2) continue;
            tmp -= d1;
            d2 = tmp/10;

            if(month == d1*d2)res++;
        }
    }
  cout << res << endl;
}