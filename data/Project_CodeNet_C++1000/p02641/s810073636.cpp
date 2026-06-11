#include <iostream>
#include <string>

using namespace std;

void insertionSort(int A[],int N){
    int i, j, v;

    for(i = 1; i < N; ++i){
        v = A[i];
        j = i - 1;

        while (j >= 0 && v < A[j]){
            A[j + 1] = A[j];
            j--;
        }

        A[j + 1] = v;
    }
}

int main(){
    int X, N, p[102], num;
    bool flag = 1;

    cin >> X >> N;
    for(int i = 0; i < N; i ++){
        cin >> p[i];
    }
    insertionSort(p, N);

    for(int j = 0; j < N; j ++){
        if(X == p[j]){
            flag = 0;
            num = j;
        }
    }
    if(flag){
        cout << X << endl;
        return 0;
    }
    for(int k = 1; k < N; k ++){
        if(0 <= num - k && p[num - k] != (p[num] - k)){
            cout << p[num] - k << endl;
            return 0;
        }
        if(num + k < N && p[num + k] != (p[num] + k)){
            cout << p[num] + k << endl;
            return 0;
        }
    }
    if (abs(X - p[0]) <= abs(X - p[N - 1])) cout << p[0] - 1;
	else cout << p[N - 1] + 1;
    return 0;
}