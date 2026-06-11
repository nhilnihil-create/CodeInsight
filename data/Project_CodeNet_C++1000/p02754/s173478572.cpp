#include <bits/stdc++.h>
using namespace std;
 
string S; int N, cnt;
 
int main() {
	long long int N,A,B;
    cin >> N >> A >> B;
    long long int Ans =0;
    long long int C =N/(A+B);
    Ans=A*C;
    if(N%(A+B)!=0){
        if(A<=N%(A+B))Ans+=A;
        else Ans+=N%(A+B);
    }
    cout << Ans << endl;
}