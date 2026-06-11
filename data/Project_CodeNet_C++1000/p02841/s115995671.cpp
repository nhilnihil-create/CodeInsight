#include <bits/stdc++.h>
using namespace std;

int main()
{
int N1,N2,W1,W2;
cin >> N1 >>N2;
cin >> W1 >>W2;
int chk=0;
if((W2-N2)<0)
{
    chk=1;
}
cout << chk << endl;
}