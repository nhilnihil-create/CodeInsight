#include <iostream>
#include <bits/stdc++.h>

using namespace std;

int main()
{
    cout<<setprecision(6)<<fixed;
    int len;
    double p1=0, p2=0, p3=0, pI=0, aux;
    cin>>len;
    double vect1[len], vect2[len];
    for(int i = 0; i<len; i++)
        cin>>vect1[i];
    for(int i = 0; i<len; i++)
        cin>>vect2[i];
    for(int i = 0; i<len; i++)
    {
        aux = abs(vect1[i] - vect2[i]);
        p1 += aux;
        p2 += pow(aux, 2);
        p3 += pow(aux, 3);
        pI = max(pI,aux);
    }
    cout<<p1<<endl;
    cout<<sqrt(p2)<<endl;
    cout<<cbrt(p3)<<endl;
    cout<<pI<<endl;
    return 0;
}
