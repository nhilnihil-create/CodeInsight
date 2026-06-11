#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define MAX 100000
void inarray(int a[], int n){
    for(int i = 0; i < n; i++) cin >> a[i];
}

int main(){
    int a,b,c,d; cin >> a >> b >> c >> d;
    int i = 0;
    while(a > 0 && c > 0){
        if(i % 2 == 0){
            c -= b;
        }else{
            a -= d;
        }
        i++;
    }
    if(a <= 0) cout << "No" << endl;
    else cout << "Yes" << endl;
    return 0;
}