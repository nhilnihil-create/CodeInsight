#include <iostream>
#include <vector>
#include <queue>
#include <cmath>
#include <algorithm>
#include <string>
#include<regex>
using namespace std;

int main()
{
    int n;
    cin >> n;
    long long int a[n+1];
    long long int b[n+1];
    long long int suma=0;
    for(int i=0;i<=n;i++){
        cin >> a[i];
        suma+=a[i];
    }
    long long int res=0;
    b[0]=1;
    res+=b[0];
    if(a[0]>=2 || (a[0]==1 && suma-1>0)){
        cout << -1 << endl;
            return 0;
    }
    for(int i=1;i<=n;i++){
        suma-=a[i-1];
        if(suma>=(b[i-1]-a[i-1])*2){
            b[i]=(b[i-1]-a[i-1])*2;
        }else{
            b[i]=suma;
        }
        res+=b[i];
        if(b[i]-a[i]<0){
            cout << -1 << endl;
            return 0;
        }else if(b[i]==a[i] && suma-a[i]>0){
            cout << -1 << endl;
            return 0;
        }
    }

    cout << res << endl;
    
    return 0;
}