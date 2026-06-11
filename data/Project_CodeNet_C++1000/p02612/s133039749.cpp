#include <bits/stdc++.h>
using namespace std;
#define endl '\n';

int main()
{
    int costo, vueltas, billete, aux;
    cin >> costo;
    aux = costo % 1000;
    billete = (costo / 1000) * 1000;
    if(aux > 0)
        billete += 1000;
    vueltas = billete - costo;
    cout << vueltas << endl;
}