#include<vector>
#include<iostream>
#include<stdio.h>
#include<stdlib.h>
#include <iostream>
#include <algorithm>
#include <map>
#include <cmath>
#include<queue>
#include <sstream>
#include <set>
#include<stack>

const long long MOD = 1000000007;
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

//切り上げ
//ceil
//floor

typedef struct _Block{
    llong a;
    llong b;
    llong c;
    llong d;
}Block; 

llong dfs(vector<Block> &Table, vector<llong> &A, llong value, llong M, llong N){
    llong maxv = 0;
    if(A.size()==N){
        llong ans = 0;
        for(int i=0; i<Table.size(); i++){
            if((A[Table[i].b]-A[Table[i].a])==Table[i].c){
                ans = ans + Table[i].d;
            }
        }
        return ans;
    }
    for(int i=value; i<=M; i++){
        A.push_back(i);
        maxv = max(maxv, dfs(Table, A, i, M, N));
        A.pop_back();
    }
    return maxv;
}

int main(){
    llong N, M, Q;
    cin >> N >> M >> Q;
    vector<llong> A;
    vector<Block> Table(Q);
    for(int i=0; i<Q; i++){
        cin >> Table[i].a >> Table[i].b >> Table[i].c >> Table[i].d;
        Table[i].a--;
        Table[i].b--; 
    }
    cout << dfs(Table, A, 1, M, N) << endl;
    return 0;
}
