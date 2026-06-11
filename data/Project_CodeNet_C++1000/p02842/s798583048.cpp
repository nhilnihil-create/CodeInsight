#include <iostream>
#include <bitset>
#include <vector>
using namespace std;

int main() {

    int N;

    int X;

    cin >> N ;

     X = N / 1.08;

    // // X * 1.08 = N
    //  cout << "---" << N << endl;
    //  cout << "---" << X << endl;
    //  cout << "(X + 1) * 1.08 : " << (X + 1) * 1.08  << endl;

   

    if (X * 1.08 == N){

        cout << X << endl;
    }
    else if (int((X + 1) * 1.08) == N){

        cout << (X + 1) << endl;
    }
    else{

        cout << ":(" << endl;
    }








}