#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); i++)
using namespace std;

int main(){
    int k;
    cin >> k;
    vector<int> v(33);
    v[1]=1;
    v[2]=1;
    v[3]=1;
    v[4]=2;
    v[5]=1;
    v[6]=2;
    v[7]=1;
    v[8]=5;
    v[9]=2;
    v[10]=2;
    v[11]=1;
    v[12]=5;
    v[13]=1;
    v[14]=2;
    v[15]=1;
    v[16]=14;
    v[17]=1;
    v[18]=5;
    v[19]=1;
    v[20]=5;
    v[21]=2;
    v[22]=2;
    v[23]=1;
    v[24]=15;
    v[25]=2;
    v[26]=2;
    v[27]=5;
    v[28]=4;
    v[29]=1;
    v[30]=4;
    v[31]=1;
    v[32]=51;
    cout << v[k] << endl;
}

//2, 2, 5, 4, 1, 4, 1, 51