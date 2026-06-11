#include<bits/stdc++.h>

using namespace std;

int main(){
    int x;
    cin >> x;
    
    int s, aux;
    aux = x / 500;
    s = aux * 1000;
    x = x - (aux * 500);
    aux = x / 5;
    s = s + (aux * 5);

    cout << s << endl;


    
    return 0;
}