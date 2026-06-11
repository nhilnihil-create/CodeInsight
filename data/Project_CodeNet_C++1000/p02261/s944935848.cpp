//なぜかAOJでWrong Answerになる！
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

int main(){
	char A_symbol[36+1];//列の文字のみを格納する配列
	char A_symboltmp[36+1];
	int A_num[36+1];//列の数字のみ格納する配列
	int A_numtmp[36+1];
	int num;//数列の長さ(カードの枚数)
	char tmpstr[3];

	/*配列を0で初期化modify
	for(int i=0;i<1001;i++){
		A[i] = 0;
	}
	*/

	cin >>num;
	
	for(int i=0;i<num;i++){
		scanf("%s",tmpstr);
		A_symbol[i]=tmpstr[0];
		A_symboltmp[i] = A_symbol[i];
		A_num[i] = atoi(&tmpstr[1]);
		A_numtmp[i] = A_num[i];
		//cout <<A_symbol[i] <<A_num[i] <<endl;
	}

	void bubbleSort(char A_symbol[],int A_num[],int N);
	void selectionSort(char A_symbol[],int A_num[],int N);
	
	bubbleSort(A_symboltmp,A_numtmp,num);//ほんとはポインタで定義してやるべき
	cout <<"Stable" <<endl;
	selectionSort(A_symbol,A_num,num);
	
	//バブルソートが常に安定なソートであることを利用して選択ソートが安定であるかどうかを判断
	for(int i=0;i<num;i++){
		if(A_numtmp[i] != A_num[i] || A_symbol[i] != A_symboltmp[i]){
			cout <<"Not stable" <<endl;
			return 0;
		}
	}
	cout <<"Stable" <<endl ;

	
	return 0;
}

void selectionSort(char A_symbol[], int A_num[],int N){
	int minj;//minjはA[i]?A[N-1]の最小値の添え字
	char tmpstr;
	int tmp;
	int cnt=0;//交換回数
	for(int i=0;i<N;i++){
		minj = i;
		for(int j=i;j<N;j++){
			if(A_num[j] < A_num[minj]){
				minj = j;
			}
		}
		
		if(minj != i){//iより後ろにiより小さいものがない場合
			cnt++;
			tmpstr = A_symbol[minj];
			A_symbol[minj] = A_symbol[i];
			A_symbol[i] = tmpstr;
			tmp = A_num[minj];
			A_num[minj] = A_num[i];
			A_num[i] = tmp;
		}


		//minj = iの場合，実際は交換になっていないのでこの場合はcnt++しない！
		
	}
	//ソート完了後の状態を出力
		for(int k=0;k<N-1;k++){
			cout <<A_symbol[k] <<A_num[k] <<" ";
		}
		cout <<A_symbol[N-1] <<A_num[N-1] ;
		cout <<endl;
		//cout <<cnt <<endl;

}

void bubbleSort(char A_symbol[],int A_num[],int N){
	bool flag = true;
	int tmp;
	int tmpstr;
	int cnt = 0;//交換回数のカウンタ

	/*まずソートを行う前の状態を出力
	for(int k=0;k<N-1;k++){
			cout <<A[k] <<" ";
		}
		cout <<A[N-1];
		cout <<endl;
		*/

	while(flag){
		flag = false;

		//交換が一回も行われなかった場合flag = trueでforループを抜ける
		for(int j=N-1;j>0;j--){
			if(A_num[j] < A_num[j-1]){
				tmp = A_num[j];
				A_num[j] = A_num[j-1];
				A_num[j-1] = tmp;
				tmpstr = A_symbol[j];
				A_symbol[j] = A_symbol[j-1];
				A_symbol[j-1] = tmpstr;
				cnt++;
				flag = true;
			}
		}
		/*この交換後の状態を出力
		for(int k=0;k<N-1;k++){
			cout <<A[k] <<" ";
		}
		cout <<A[N-1];
		cout <<endl;
		*/
	}
	/*ソート終了後の状態を出力*/
	for(int k=0;k<N-1;k++){
			cout <<A_symbol[k] << A_num[k] <<" ";
	}
	cout <<A_symbol[N-1] <<A_num[N-1] ;
	cout <<endl;
}