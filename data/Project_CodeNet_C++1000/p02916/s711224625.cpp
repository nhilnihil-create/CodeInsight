#include <iostream> 

using namespace std;

int main(){
    int N;
    int sum =0;
    cin >> N;
    int A[N];
    int B[N];
    int C[N-1];
    for(int i = 0;i < N; i++)
    {
        cin >> A[i];
    }
    for(int i = 0;i < N; i++)
    {
        cin >> B[i];
    }
    for(int i = 0;i < N-1; i++)
    {
        cin >> C[i];
    }
    for(int i = 0;i < N-1; i++)
    {
        sum = sum + B[i];
        if(A[i+1] == A[i]+1)
        {
            sum = sum + C[A[i]-1];
        }
    }
    sum = sum + B[N-1];
    cout << sum << endl;
    return 0;
}