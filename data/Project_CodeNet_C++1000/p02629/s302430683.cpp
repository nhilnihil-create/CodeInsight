#include <iostream>
#include <string>
using namespace std;

//a,...,z,aa,ab,...,zy,zz,aaa,aab,...zzy,zzz,aaaa...と犬に名付ける
//N匹目の名前は?(N<=1000000000000001)
//長さnの名前は26^n通りある
int main(){
    long long int N;
    cin >> N;
    string name = "";

    //a,...,zの文字を格納
    char c[26];
    for(int i=0;i<26;++i){
        c[i]='a'+i;
    }

    //文字数を固定して0スタートにする
    N=N-1;
    long long int pow = 26;
    int count=1;//文字数
    while(true){
        if(N>=pow){
            N=N-pow;
            ++count;
        } else {
            break;
        }
        pow=pow*26;
    }

    //文字列を作る
    while(N>0){
        name=c[N%26]+name;
        --count;
        N=N/26;
    }
    //文字数を満たすまでaを追加
    for(int i=0;i<count;++i){
        name='a'+name;
    }

    cout << name << endl;
}
