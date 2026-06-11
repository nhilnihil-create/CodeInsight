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
    int A,B,C,K;
    cin >> A >>B >>C >>K;
    int sum = 0;

    int a_num=A;
    if(A>K){
      a_num =K;
    }
    K -= a_num;
    sum += a_num;

    int b_num =B;
    if(B>K){
      b_num = K;
    }
    K -= b_num;

    int c_num = C;
    if(C>K){
      c_num = K;
    }
    sum -= c_num;
    printl(sum);
}
