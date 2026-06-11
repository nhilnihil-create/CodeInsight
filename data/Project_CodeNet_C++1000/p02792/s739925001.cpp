#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int a[22][22]={0};
int get1(int a){
    while(a>=10)
        a/=10;
    return a;
}
int main()
{
    int n;int ans= 0;
    cin >> n;
    for(int i=1;i<=n;i++){
        
            a[get1(i)][i%10]++;
    }
    for(int i=1;i<=n;i++){
        if(i%10)
            ans+=a[i%10][get1(i)];
    }

//    for(int i=1;i<10;i++){
//        for(int j=1;j<10;j++){
//            ans+=a[i][j]+a[j][i];
//        }
//    }
    cout <<ans <<endl;
    return 0;
}

//112 111 111 111 111 111 111 111 111
//13 14 13 13 13 13 13 13 13
//11 11 12 11 11 11 11 11 11
//11 11 11 12 11 11 11 11 11
//11 11 11 11 12 11 11 11 11
//11 11 11 11 11 12 11 11 11
//11 11 11 11 11 11 12 11 11
//11 11 11 11 11 11 11 12 11
//11 11 11 11 11 11 11 11 12
//40812


