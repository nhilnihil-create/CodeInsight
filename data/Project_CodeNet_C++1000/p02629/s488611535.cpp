#include <iostream>
#include <string>
using namespace std;

int64_t N;
//N_max = 1000000000000001
string str = "";

void input(){
    cin >> N;
}

void solve(){
    //a~z,aa~zz,aaa~zzz 26進数ってことやな。最大10桁
    int res;

    for (int i=0;i<11;i++){
        N=N-1;
        res = N%26;
        N = N/26;
        str = char('a' + res) + str;
        if (N==0) break;
    }
    cout << str << endl; 
}

int main(){
    input();
    solve();
    return 0;
}