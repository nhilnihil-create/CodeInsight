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
#include <utility>
#include <tuple>
#define INF 1000000000000
const long long MOD = 998244353;

using namespace std;
typedef long long llong;
#define debug cout << "Hello" << endl;
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

void dfs(llong prev_node, llong node, map<llong, llong> &Table, vector<llong> &ans, vector<vector<llong> > &graph){
    ans[node] += ans[prev_node];
    ans[node] += Table[node];
    for(int i=0; i<graph[node].size(); i++){
        dfs(node, graph[node][i], Table, ans, graph);
    }
    return;
}

int main(){
    llong N,Q;
    cin >> N >> Q;
    llong a,b;
    vector<vector<llong> > graph(N);
    vector<vector<llong> > directed_graph(N);
    vector<llong> ans(N, 0);
    map<llong, llong> Table;
    llong p,x;
    queue<llong> Queue;
    vector<bool> visited(N, false);
    llong node;

    for(int i=0; i<N-1; i++){
        cin >> a >> b;
        graph[a-1].push_back(b-1);
        graph[b-1].push_back(a-1);
    }
    for(int i=0; i<Q; i++){
        cin >> p >> x;
        Table[p-1] += x;
    }

    ans[0] += Table[0];

    Queue.push(0);

    while(!Queue.empty()){
        node = Queue.front();
        Queue.pop();
        visited[node] = true;
        for(int i=0; i<graph[node].size(); i++){
            if(visited[graph[node][i]]){
                continue;
            }
            Queue.push(graph[node][i]);
            directed_graph[node].push_back(graph[node][i]);
        }
    }
    for(int i=0; i<directed_graph[0].size(); i++){
        dfs(0, graph[0][i], Table, ans, directed_graph);
    }   
    for(int i=0; i<ans.size()-1; i++){
        cout << ans[i] << " ";
    }
    cout << ans[ans.size()-1] << endl;
    return 0;
}