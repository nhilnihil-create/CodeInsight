#include<iostream>
#include<math.h>

#define oo 0xffffff
#define endl '\n'
int ten = 10;
using namespace std;

char s[1000001];

int main (){
    long long int t,n,i,j,m,res1;
    cin >> n;
    if(n==1){
        cout << "0";
        return 0;
    }
    long long int res = sqrt(n);
    int cnt=0;
    for(i=2;i*i<=n;i++){
        if(n%i==0){
            j=i;
            while(n%j==0){
                n/=j;
                j*=i;
                cnt++;
            }
            while(n%i==0){
                n/=i;
            }
        }
    }
    if(n>1) cnt++;
    cout << cnt ;

}
