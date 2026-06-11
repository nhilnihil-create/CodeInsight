#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
typedef long long ull;
typedef long double ld;
#define inp_arr(name,size) for(int i = 0;i<size;i++)\
cin >> name[i];
#define cepat cin.tie(0);


int main(){
    cepat

    int a,max;
    cin >> a >> max;
    int d = 0, boun = 1;
    vector<int>data(a);
    inp_arr(data,a);
    for(int i = 0;i<a;i++){
        if(d+data[i]>max)
            break;
        d += data[i];
        boun++;

    }
    cout << boun;


    return 0;
}






