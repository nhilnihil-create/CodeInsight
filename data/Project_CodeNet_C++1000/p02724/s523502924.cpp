#include<bits/stdc++.h>
#define _ ios_base::sync_with_stdio(0);

using namespace std;

int main(){_
    int x;
    int t1 = 1000,t2 = 5;
    cin >> x;
    int quociente = x/500;
    int resto = x%500;
    resto /= 5;
    long int resposta = (quociente*t1) + (resto*t2);
    cout << resposta << endl;
    return 0;
}