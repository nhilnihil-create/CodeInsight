#include<vector>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include <iostream>
#include <algorithm>
#define INF 100000000000000
using namespace std;
typedef long long llong;

//int isalpha(char ch): ch がアルファベットなら true を返す
//int isdigit(char ch): ch が数字なら true を返す
//int islower(char ch): ch が小文字なら true を返す
//int isupper(char ch): ch が大文字なら true を返す
//int tolower(char ch): ch の小文字を返す
//int toupper(char ch): ch の大文字を返す

//string型
//size()	文字数を返す
//insert()	（指定した場所に）文字・文字列を挿入する
//erase()	（指定した場所の）文字・文字列を削除する
//clear()	すべての文字を削除する
//substr()	文字列の（指定した）部分文字列を返す
//replace()	（指定した）部分文字列を新しい文字列に置換する
//文字列の比較は、<=や==などを使え
//replace関数を使い、簡単に文字列を置換
//リバース関数：reverse(str.begin(), str.end());

//グラフ理論用変数
//vector<vector<llong> > graph(N);


int main(){
    llong X,Y;
    cin >> X >> Y;

    for(int i=0; i<=100; i=i+2){
        for(int j=0; j<=100; j=j+4){
            if(Y==(i+j) && X==(i/2+j/4)){
                cout << "Yes" << endl;
                exit(0);
            }
        }
    }
    cout << "No" << endl;
}