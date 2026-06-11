#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <vector>//子のセットを記録
#include <string>//ノードのタイプ(root、internal node、leafのいずれか)を記録
#include <algorithm>
#include <iterator>//back_inserter
#define N_MAX 100000
#define MAX_DEPTH
#define NIL -1//親や子などが存在しない場合に用いる
using namespace std;
//常に心してかかれ
//簡単なことを簡単にできるように練習する
//びっくりするくらいつまらないことで詰まってることも多い
//それでも不具合の可能性は常にある

int n;//num of input (=num of nodes)



class node{
	/*今回の場合，その節点の親，一番左の子，すぐ右の兄弟からその節点
	 *を特徴づけることができる
	 */
public:
	int parent;
	int leftest_child;
	int nearest_right_slimbs;
	int depth;

};

node list[N_MAX+1];
int setDepth(int u){
	int d = 0;//whileは先判定なのでNILではまずい
	while(list[u].parent != NIL){
		u = list[u].parent;//uは値渡しなのでこれで問題ない
		d++;
	}
	return d;
}

void print(int u){
	int c;
	cout <<"node " <<u <<": ";
	cout <<"parent = " <<list[u].parent <<", ";
	cout <<"depth = " <<list[u].depth <<", ";

	if(list[u].parent == NIL) cout <<"root, ";
	else if(list[u].leftest_child == NIL) cout <<"leaf, ";
	else cout <<"internal node, ";

	cout <<"[";

	c=list[u].leftest_child;
	for(int i=0;c != NIL;i++){
		if(i>0)cout <<", ";
		cout <<c;
		c = list[c].nearest_right_slimbs;
	}
	cout <<"]" <<endl;
}

int main(){
	int root_id;
	int id_tmp;
	int numchld_tmp;
	int chldid_tmp;
	int prvs_chldid;

	

	for(int i=0;i<N_MAX;i++){//初期化
		list[i].leftest_child = list[i].nearest_right_slimbs = list[i].parent = list[i].depth = NIL;
	}

	scanf("%d",&n);

	for(int i=0;i<n;i++){
		scanf("%d",&id_tmp);
		scanf("%d",&numchld_tmp);

		
		//numchld_tmp == 0のときはこのループは回らないが初期化が適切なので問題ない
		for(int j=0;j<numchld_tmp;j++){
			scanf("%d",&chldid_tmp);
			if(j == 0){//一番左の子
				list[id_tmp].leftest_child = chldid_tmp;
			}else{//j>0
				list[prvs_chldid].nearest_right_slimbs = chldid_tmp;//ひとつ前の子のすぐ右の子
			}
			prvs_chldid = chldid_tmp;
			list[chldid_tmp].parent = id_tmp;
		}
	}

	//親の探索
	for(int i=0;i<n;i++){
		if(list[i].parent == -1){
			root_id = i;
		}
	}

	for(int i=0;i<n;i++){
		list[i].depth = setDepth(i);
	}

	for(int i=0;i<n;i++){
		print(i);
	}

	return 0;
}
/*雑記
class node{
public:
	int node_id;
	int parent;
	int depth;
	string type;
	vector<int> list_of_children;/*vector<int> list_of_children();だとエラーになるなんで？
								  *これだとvector<int>型の返り値をもつ引数なしのlist_of_children
								  *という名前のメンバ関数のプロトタイプ宣言をしてしまってる．
								  *引数なしのコンストラクタを用いるときは後ろに()を付けないこと！
								  *//*
	node(){
	}

	node(int NODE_ID){
		node_id = NODE_ID;
	}

	void setListOfChildren(int num){
		int tmp;

		for(int i=0;i<num;i++){
			scanf("%d",&tmp);
			list_of_children.push_back(tmp);
		}
	}

};
*/