#include <bits/stdc++.h>

using namespace std;

int main(void)
{
    long long A, B, N;
    cin >> A >> B >> N;

    // expr = floor(A * x / B) = ((A * x) - (A * x) % B) / B
    // A * floor(x / B) = A * (x - (x % B)) / B
    // floor(A * x / B) - A * floor(x / B) = (A * (x % B) - (A * x) % B) / B
    // (A * x) % B =  A * (x % B) % B
    // expr = A * (x % B - (x % B) % B) / B
    //      = A / B * floor (x % B)

    if(N >= B - 1){
        cout << floor(A * (B - 1) / B) - A * floor((B - 1)/B) << endl;
    } 
    else {
        cout << floor(A * N / B) - A * floor(N / B)<< endl;
    }


    return 0;

}