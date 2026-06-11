#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll inf = 1e9+7;

int main(){

    int n;
    cin>>n;
    int f = n%10;

    if (f == 3){
        cout << "bon" << endl;

    }else if (f<= 1 || f==6||f==8){
        cout << "pon"<<endl;

    }else{
        cout << "hon" << endl;
    }


}


