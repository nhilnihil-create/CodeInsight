#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <string>
#include <vector>
#include <algorithm>
#define rep(i,e)for(int i=0;i<e;i++)
#define PI acos(-1)
using namespace std;
#define toLower(str)transform(str.begin(),str.end(),str.begin(),::tolower)

int main(){
    int i, j;
    int n;
    cin >> n;
    cout << n << ":";
    int n1 = n;
    while(n%2==0){
        cout << " 2";
        n/=2; 
    }
    for(i=3;i*i<n1;i+=2){
        while(n%i==0){
            cout << " " << i;
            n/=i;
        }
    }
    if(n!=1)cout << " " << n;
    cout << endl;
    return 0;
}
