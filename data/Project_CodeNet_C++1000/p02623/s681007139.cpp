#include <iostream>
using namespace std;

//Ai分かかる本の列(1<=i<=N)とBi分かかる本の列(1<=i<=M)がある
//それぞれにおいて上(インデックスの小さいもの)から順に読める
//列を選びつつ読んでK分を超えない最大冊数を求める
int main(){
    int N,M;
    long long int K;
    cin >> N >> M >> K;
    long long int* A = new long long int[N];
    long long int* B = new long long int[M];
    for(int i=0;i<N;++i){
        cin >> A[i];
    }
    for(int i=0;i<M;++i){
        cin >> B[i];
    }

    long long int sum=0;
    int index=N-1;

    //Aから条件の範囲内で本をとる
    for(int i=0;i<N;++i){
        sum=sum+A[i];
        if(sum>K){
            sum=sum-A[i];
            index=i-1;
            break;
        }
    }

    //Aの本を減らしてBの本をとる
    int j=0;//Bのインデクス
    //Aが全部入る場合を考慮して、Bの追加を最初に行う
    while(true){
        if(j>=M){
            break;
        }
        if(sum+B[j] > K){
            break;
        }
        sum=sum+B[j];
        ++j;
    }
    int max=index+1+j;//最大冊数
    for(int i=index;i>=0;--i){
        sum=sum-A[i];//Aの本を減らす

        //Bの本をできるだけとる
        while(true){
            if(j>=M){
                break;
            }
            if(sum+B[j] > K){
                break;
            }
            sum=sum+B[j];
            ++j;
        }

        //この時点で、Aはi-1番目まで、Bはj-1番目まで入っている(0スタート)
        if(i+j > max){
            max=i+j;
        }
    }

    cout << max << endl;
    delete[] A;
    delete[] B;
}