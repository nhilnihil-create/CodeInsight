#include<vector>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include<queue>

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
//Insert()	（指定した場所に）文字・文字列を挿入する
//erase()	（指定した場所の）文字・文字列を削除する
//clear()	すべての文字を削除する
//substr()	文字列の（指定した）部分文字列を返す
//replace()	（指定した）部分文字列を新しい文字列に置換する
//c_str()変換
//文字列の比較は、<=や==などを使え
//replace関数を使い、簡単に文字列を置換
//リバース関数：reverse(str.begin(), str.end());
//map<type, type> dict;で宣言
//グラフ理論用変数
//vector<vector<llong> > graph(N);

//ソート
//降順sort(v.begin(), v.end(), std::greater<Type>());

//大文字から小文字へんかん
//w[i] = w[i]-'A'+'a';

//vector
//assignメソッド　引数：サイズ、値
//与えられたサイズと値でvectorを初期化する

//queueクラス
//find()次に取り出す値の表示をする。
//pop()値を取り出す。戻り値はなし
//push()キューに値をプッシュする

//priority_queueクラス

int main(){
    //bit全探索
    llong N;
    cin >> N;
    vector<vector<pair<llong, bool> > > Table(N);
    llong A;
    llong x,y;
    llong maxv = INF*-1;
    llong cnt;
    pair<llong, bool> X;
    unsigned char flg;
    for(int i=0; i<N; i++){
        cin >> A;
        for(int j=0; j<A; j++){
            cin >> x >> y;
            if(y==1){
                X.second = true;
            }else{
                X.second = false;
            }
            X.first = x-1;
            Table[i].push_back(X);
        }
    }
    for(int i=0; i<pow(2,N); i++){
        vector<bool> list(N, false);
        for(int j=0; j<N; j++){
            if((i>>j)&1){
                list[j] = true;
            }
        }
        cnt = 0;
        flg = 0;
        for(int i=0; i<N; i++){
            for(int j=0; j<Table[i].size(); j++){
                if(list[i] && list[Table[i][j].first]!=Table[i][j].second){
                    flg = 1;
                }
            }
        }
        if(flg==0){
            for(int i=0; i<N; i++){
                if(list[i]==true){
                    cnt++;
                }
            }
            maxv = max(maxv, cnt);
        }
    }
    cout << maxv << endl;
    return 0;
}



