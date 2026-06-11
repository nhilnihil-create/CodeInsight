#include<stdio.h>
#include<iostream>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;

const int MAX = 1000001;

int GCD(int a,int b){
    if(a < b)swap(a,b);
    if(a % b)return GCD(b,a % b);
    return b;
}

int main(){
    int N;
    int A[MAX];
    int table[MAX] = {0};
    bool pc = true;
    bool sc = true;

    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> A[i];
        table[A[i]]++;
    }

    for(int i = 2;i < MAX;i++){
        int cnt = 0;
        for(int j = i;j < MAX;j += i){
            cnt += table[j];
        }
        if(cnt >= 2){
            pc = false;
            break;
        }
    }

    int gcd = A[0];
    for(int i = 1;i < N;i++){
        gcd = GCD(gcd,A[i]);
    }
    if(gcd != 1){
        sc = false;
    }

    if(pc){
        cout << "pairwise coprime" << endl;
    }else if(sc){
        cout << "setwise coprime" << endl;
    }else{
        cout << "not coprime" << endl;
    }

    return 0;
}

