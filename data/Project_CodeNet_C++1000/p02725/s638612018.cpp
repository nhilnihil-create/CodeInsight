#include<iostream>
using namespace std;

int K, N;
int A[200000];


// int index = 0;

int main(){
    cin >> K >> N;

    int diff_max = 0;
    cin >> A[0];
    for (int i = 1; i < N; i++)
    {
        cin >> A[i];
        if (A[i] - A[i - 1] > diff_max)
        {
            diff_max = A[i] - A[i - 1];
        }
    }
    if(K - A[N - 1] + A[0] > diff_max){
        diff_max = K - A[N - 1] + A[0];
    }

    cout << K - diff_max << endl;
}