
#include <iostream>
#include <iomanip>
/*cout <<setprecision(11)<<ret<<endl;で、数字部分を計11桁表示*/
#include <cstdio>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>
#include <queue>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//Shift+Command+bでデバッグ
//その後ターミナルで./a.outを実行
//入力を貼り付ける

//////////////////
//  A
/*int main(void){
    vector<int> a(3);
    cin>>a[0]>>a[1]>>a[2];

    sort(a.begin(),a.end());

    cout<<a[0]+a[1]<<endl;
    return 0;
}*/
//////////////////
//  B
int main(void){
    int n,sum=0;cin>>n;
    vector<int> a(n);

    rep(i,n){
        cin>>a[i];
        sum+=a[i];
    }
    int tmpsum=0,mini=sum;
    rep(i,n){
        tmpsum+=a[i];
        mini=min( mini, abs(tmpsum-(sum-tmpsum)) );
    }
    cout<<mini<<endl;
    return 0;
}
//////////////////
//  C
/*int main(void){

    return 0;
}*/
//////////////////
//  D
/*int main(void){

    return 0;
}*/
//////////////////
//  E
/*int main(void){

    return 0;
}*/
//////////////////
//  F
/*int main(void){

    return 0;
}*/
