#include <bits/stdc++.h>
using namespace std;

typedef long long ll;



int main(){

    int h1,m1,h2,m2,k;
    cin>>h1>>m1>>h2>>m2>>k;
    int sum = (h2-h1)*60;
    int xx = m2-m1;
    sum +=xx;
    cout<<sum-k<<endl;
    return 0;
}
