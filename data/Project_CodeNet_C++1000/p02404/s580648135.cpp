#include <iostream>
#define C cout<<
using namespace std;

/**
AOJ ITP1_5_B Print a Frame.
http://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=ITP1_5_B
*/
main() {
    int H,W,i,j;
    while(cin>>H>>W&&H){
        for(i=0;i<H;i++,C"#\n")for(j=0;j<W-1;j++)C(i*(i+1-H)*j?".":"#");
        C"\n";
    }
}