#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cmath>
using namespace std;


int GCD(int x, int y){
    if (x < y) swap(x, y);

    while (y > 0){
        x = x % y;
        swap(x, y);
    }
    return x;
}

//因数にint型の整数、出力はvector<int>型の素数配列
vector<int> Prime_Factorize(int N){
    vector<int> out;
    while (N % 2 == 0){
        N /= 2;
        out.push_back(2);
    }
    //3以上の素数は全部奇数！！
    int Odds = 3;
    while (Odds * Odds <= N){
        if (N % Odds == 0){
            N /= Odds;
            out.push_back(Odds);
        }else{
            Odds += 2;
        }
    }
    if (N != 1) out.push_back(N);

    return out;
}


int main(){
    int N;
    cin >> N;

    vector<int> A(N);
    for (int i = 0; i < N; ++i){
        cin >> A[i];
    }

    sort(A.begin(), A.end());

    int sup = 1000000;
    int flag = 0;

    int table[sup];
    for (int i = 0; i < sup; ++i){
        table[i] = 0;
    }

    for (int i = 0; i < N; ++i){
        int num = A[i];
        vector<int> lst;
        lst = Prime_Factorize(num);
        for (int j = 0; j < lst.size(); ++j){
            if (table[lst[j]] == 1) flag = 1;
        }
        for (int j = 0; j < lst.size(); ++j){
            table[lst[j]] = 1;
        }
    }
    
    if (flag == 0){
        cout << "pairwise coprime" << endl;
    }

    int gcd = A[0];
    for (int i = 1; i < N; ++i){
        gcd = GCD(gcd, A[i]);
    }

    if (flag == 1){
        if (gcd == 1){
            cout << "setwise coprime" << endl;
        } else{
            cout << "not coprime" << endl;
        }
    }
}

