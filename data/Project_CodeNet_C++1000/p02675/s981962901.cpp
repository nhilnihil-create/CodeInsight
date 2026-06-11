#include <bits/stdc++.h>
using namespace std;

#define print cout <<
#define printl(s) cout << s << endl;
#define rep(i,n) for (int i = 0; i < (n); ++i)

template <typename T>
vector<T> getValues(int num){
    vector<T> values(num);
    for(int i=0;i<num;i++){
        cin >> values.at(i);
    }
    return values;
}

int main(){
    int N;
    cin >> N;
    int digit = N %10;
    string ans = "hon";
    if(digit==0 ||digit==1 || digit==6 ||digit==8){
      ans = "pon";
    }else if(digit == 3){
      ans = "bon";
    }
    printl(ans);
}
