#include <bits/stdc++.h>
using namespace std;

#define printl(s) cout << s << endl;
#define rep(i,n) for (int i = 0; i < (n); ++i)

int main(){
    int N;
    cin >> N;
    int tmp = N %1000;
    if(tmp!=0){
      printl(1000 - tmp);
    }else{
      printl(0);
    }
}
