#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int c =0 , N,a;

    vector <int> A;

    cin>> N;

    while (N){
        cin >> a;
        A.push_back(a);
        N--;
    } for(int i = 0; i< A.size(); i +=2)
        if (A[i] % 2 !=0)
            c++;
        cout<<c ;


    return 0;

}
