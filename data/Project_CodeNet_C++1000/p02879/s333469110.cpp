#include <bits/stdc++.h>
using namespace std;
using vec_int = vector<int>;
using P = pair<int,int>;
using T = tuple<int,int,int>;
using ll = long long;
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

int charToInt(char c){
    char zero_num = '0';
    return (int)c - (int)zero_num;
}

int main(){
    int A,B;cin>>A>>B;
    if(A>=10 || B>=10){
        cout<<-1<<endl;
        return 0;
    }

        cout<<A*B<<endl;
    return 0;
}