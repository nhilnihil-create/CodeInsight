#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    int price=N*100/108;

    if(price*108/100==N && N*100%108==0) cout << price << endl;
    else if((price+1)*108/100==N && N*100%108!=0) cout << price+1 << endl;
    else cout << ":(" << endl;
}