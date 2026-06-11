// シェルソート
#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>

using namespace std;

const int MAX_N = 1000000;

int cnt = 0;
vector<int> G;

void insertionSort(int A[], int n, int g);
void shellSort(int A[], int n);

int main(void)
{
    int N;
    int ary_sequence[MAX_N];

    cin >> N;

    for(int i = 0; i < N; i++)
    {
        cin >> ary_sequence[i];
    }

    shellSort(&ary_sequence[0], N);

    cout << G.size() << endl;

    for(int i = G.size() - 1; i >= 0; i--)
    {
        cout << G[i];

        if( i )
        {
            cout << " ";
        }
    }

    cout << endl;
    cout << cnt << endl;

    // 最終結果の表示
    for(int i = 0; i < N; i++)
    {
    	cout << ary_sequence[i] << endl;
    }

    return 0;

}

// シェルソートを実施する関数
void shellSort(int A[], int n)
{
    // 挿入ソートを実施する間隔
    // 数列 : G = {1, 4, 13, 40, 121, 364,・・・・}を生成
    for(int h = 1 ; ;)
    {
        if( h > n )
        {
            break;
        }

        G.push_back(h);
        h = ( 3 * h ) + 1;
    }

    for(int i = G.size() - 1; i >= 0; i--)
    {
        // 逆順にG[i] = gを指定
        insertionSort(&A[0], n, G[i]);
    }

    return;
}

// 挿入ソートを実施する関数
// g : 挿入ソートを実施する間隔
void insertionSort(int A[], int n, int g)
{
    int v, j;

    for(int i = g; i < n; i++)
    {
        // 挿入する値をラッチする
        v = A[i];
        // 比較対象の要素No.を設定する
        j = i - g;

        while( j >= 0 && A[j] > v )
        {
            // vよりも値が大きいは後ろにコピーして、前の要素へ戻る
            A[j + g] = A[j];
            j = j - g;

            // 交換回数のカウント
            cnt++;
        }

        // 値のソートで、値を入れるべき所に値を入れる
        A[j + g] = v;

    }

    return;
}

